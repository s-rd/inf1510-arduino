using namespace std;
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>


/* Questions */
const int questionAmount = 7;
const String questions[7][5] = {
  {"Hvem er stats- minister i Norge?",          "Erna Solberg",       "Jens Stoltenberg", "Bjornar Moxnes",   "1" },
  {"Hvilket parti leder Erna Solberg?",         "Arbeiderpartiet",    "Hoyre",            "Venstre"       ,   "2" },
  {"Hvilket parti har flest medlemmer?",        "Venstre",            "Hoyre",            "Arbeiderpartiet",  "3" },
  {"Hvilket parti ligger mest mot hoyre?",      "FrP",                "Rodt",             "KrF",              "1" },
  {"Hvem er leder i Senterpartiet?",            "Siv Jensen",         "Jonas G. Store",   "Trygve S. Vedum",  "3" },
  {"Hvem er leder i Fremskrittspartiet?",       "Audun Lysbakken",    "Siv Jensen",       "Liv Navarsete" ,   "2" },
  {"Hvilket parti er opptatt av landbruk?",     "Mdg",                "SV",               "Senterpartiet",    "3" },
};


/* Displays */
LiquidCrystal lcds[2] = {LiquidCrystal(33, 31, 29, 27, 25, 23), LiquidCrystal(45, 43, 41, 39, 37, 35)};

/* Led rings */
const int 
  neo1pin = 34,
  neo2pin = 36;
const int BRIGHTNESS = 100;
const int neos[2][3][2] = {
  {
    { 0,  16 },
    { 16, 32 },
    { 32, 48 },
  },
  {
    { 48, 64 },
    { 64, 80 },
    { 80, 96 },
  },
};


// Adafruit_NeoPixel neos[2] = {Adafruit_NeoPixel(48, neo1pin, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(48, neo1pin, NEO_GRB + NEO_KHZ800);



Adafruit_NeoPixel neo = Adafruit_NeoPixel(96, neo1pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo2 = Adafruit_NeoPixel(48, neo1pin, NEO_GRB + NEO_KHZ800);



/* Globals */
unsigned long curTime;

const int
  but1A = 24,
  but1B = 26,
  but1C = 28,
  but2A = 30,
  but2B = 32,
  but2C = 34;
const int buttonDelay = 1000;
const int questionTime = 15000;
const int coolDownTime = 3000;
unsigned long prevTime = 0;

String curQuestion[5];
boolean printNextQuestion;

int teamsAnswered;
boolean team1HasAnswered;
boolean team2HasAnswered;
boolean questionIsAnswered;

static int questionCount = 0;
static int nextQuestionId = 0;

int usedQuestions[questionAmount];

int curPoints;
int points[2];

boolean displayedScores;



void setup() {
  readyScreens();
  Serial.begin(9600);

  setQuestion(0);
  printNextQuestion = true;
  teamsAnswered = 0;
  questionIsAnswered = false;
  displayedScores = false;

  team1HasAnswered = false;
  team2HasAnswered = false;

  pinMode(but1A, INPUT_PULLUP);
  pinMode(but1B, INPUT_PULLUP);
  pinMode(but1C, INPUT_PULLUP);
  pinMode(but2A, INPUT_PULLUP);
  pinMode(but2B, INPUT_PULLUP);
  pinMode(but2C, INPUT_PULLUP);


  lcds[0].print("Starter opp!");
  lcds[1].print("Starter opp!");

  readyNeos();
}

void loop() {

  curTime = millis();
  curPoints = (questionTime - (curTime - prevTime)) / 10;


  // If next question exists
  if (hasNextQuestion()) {

    // setTeamColor(0,0,255, 0);
    // setTeamColor(0,0,255, 1);

    // If question has not been printed, print it
    if (printNextQuestion) {
      setTeamColor(0,0,255, 0);
      setTeamColor(0,0,255, 1);

      for (int i = 0; i < 32; i++) {        
        neo2.setPixelColor(i, 0,0,255);
        neo2.show();
      }
      printQuestion();
      printNextQuestion = false; // Dont print it again
    }


    // Listen for answers
    listenForAnswers();


    // If time is up,
    // or question has been answered by both teams
    if (hasWaited(curTime, questionTime) || questionIsAnswered) {

      // If one or more teams have not answered
      if (!questionIsAnswered) {
        Serial.println("\nTiden er ute!");
      }

      // Display scores
      displayScores();

      // Reset for next loop
      resetForNextLoop();

      // If there is a next question, display it
      if (hasNextQuestion()) {
        delay(coolDownTime);
        printNextQuestion = true;
      }

    }

  }


  // If has no more questions and scores have not been displayed
  if (!hasNextQuestion() && !displayedScores) {

    // Display scores
    if (getLeadingTeam() >= 0) {
      // If there is a winner
      int w = getLeadingTeam();
      int l = getLeadingTeam() == 1 ? 0 : 1;

      // Print winner message
      lcds[w].clear();
      lcds[w].setCursor(5, 1);
      lcds[w].print("Dere vant!");
      lcds[w].setCursor(5, 2);
      lcds[w].print(points[w]);
      lcds[w].print(" poeng");
      setTeamColor(0,255,0, w);

      // Print loser message
      lcds[l].clear();
      lcds[l].setCursor(0, 1);
      lcds[l].print("Kanskje neste gang..");
      lcds[l].setCursor(5, 2);
      lcds[l].print(points[l]);
      lcds[l].print(" poeng");
      setTeamColor(255,0,0, l);
      
    } else {
      // If there is a draw
      for (int i = 0; i < 2; i++) {
        lcds[i].clear();
        lcds[i].setCursor(6, 1);
        lcds[i].print("Uavgjort");
        lcds[i].setCursor(5, 2);
        lcds[i].print(points[i]);
        lcds[i].print(" poeng!");
      }
    }
    
    Serial.print("\nGratulerer til lag ");
    Serial.print(getLeadingTeam()+1);
    Serial.println("!");
    
    displayedScores = true;
  }


}



void resetForNextLoop() {
  teamsAnswered = 0;
  questionIsAnswered = false;
  team1HasAnswered = false;
  team2HasAnswered = false;

  questionCount++;
  nextQuestionId += 1;
  nextQuestion();

  prevTime = curTime;
}
boolean hasWaited(unsigned long curTime, int delayTime) {
  if ((curTime - prevTime) >= delayTime) {
    prevTime = curTime;
    return true;
  }
  return false;
}

void printQuestion() {
  Serial.print("\nSporsmal ");
  Serial.print((questionCount + 1));
  Serial.println(":");
  Serial.println(curQuestion[0]);
  Serial.println("A: " + curQuestion[1] + ". B: " + curQuestion[2] + ". C: " + curQuestion[3]);
  Serial.println();

  lcds[0].clear();
  lcds[1].clear();
  
  String question = "Sporsmal ";
  question = question + (questionCount + 1);
  
  displayText(question, 1, true, 0);
  delay(2000);
  lcds[0].clear();
  lcds[0].clear();
  displayText(curQuestion[0], 1, true, 0);
  delay(2000);

  
  displayText("A: " + curQuestion[1], 1, false, 0);
  displayText("B: " + curQuestion[2], 2, false, 0);
  displayText("C: " + curQuestion[3], 3, false, 0);
}
void setQuestion(int id) {
  for (int i = 0; i < 5; i++) {
    curQuestion[i] = questions[id][i];
  }
}
void nextQuestion() {
  setQuestion(nextQuestionId);
}
boolean hasNextQuestion() {
  if (nextQuestionId < questionAmount) return true;
  return false;
}
int getAnswerId() {
  return curQuestion[4].toInt();
}


boolean answerQuestion(int answer, int team) {

  
  setRingColor(255,255,255, team, answer);
  int correctAnswer = getAnswerId();
  correctAnswer--;
  
  boolean isCorrect = (answer == correctAnswer);
  
  if (isCorrect) {
    points[team] += curPoints;
    Serial.print("Lag ");
    Serial.print(team);
    Serial.print(": ");
    Serial.print(curPoints);
    Serial.println(" poeng!");
  } else {
    Serial.print("Lag ");
    Serial.print(team);
    Serial.println(": Feil svar!");
  }

  switch (team) {
    case 0:
      team1HasAnswered = true;
      break;
    case 1:
      team2HasAnswered = true;
      break;
  }

  teamsAnswered++;
  return isCorrect;
}
void listenForAnswers() {
  /* Team 1 */
  if (!team1HasAnswered) {
    if (!digitalRead(but1A)) {
      answerQuestion(0, 0);
    }
    else if (!digitalRead(but1B)) 
      answerQuestion(1, 0);
    }
    else if (!digitalRead(but1C)) {
      answerQuestion(2, 0);
    }
  }

  /* Team 2 */
  if (!team2HasAnswered) {
    if (!digitalRead(but2A)) {
      answerQuestion(0, 1);
    }
    else if (!digitalRead(but2B)) {
      answerQuestion(1, 1);
    }
    else if (!digitalRead(but2C)) {
      answerQuestion(2, 1);
    }
  }

  /* If both teams have answered, question is answered */
  if (teamsAnswered > 1) {
    questionIsAnswered = true;
  }
}


int getLeadingTeam() {
  if (points[0] > points[1]) return 0;
  else if (points[0] < points[1]) return 1;
  else return -1;
}

void displayScores() {
  for (int i = 0; i < 2; i++) {
    lcds[i].clear();
  
    lcds[i].setCursor(0, 1);
    lcds[i].print("    Lag 1: ");
    lcds[i].print(points[0]);
    lcds[i].print(" p");
  
    lcds[i].setCursor(0, 2);
    lcds[i].print("    Lag 2: ");
    lcds[i].print(points[1]);
    lcds[i].print(" p");
  }
  
  Serial.print("Lag 1: ");
  Serial.print(points[0]);
  Serial.print(". Lag 2: ");
  Serial.println(points[1]);
}


void clearLine(int row, int team) {
  lcds[team].setCursor(0, row);
  lcds[team].print("                    ");
  lcds[team].setCursor(0, row);
}
void centerPrintText(String text, int row, int team) {
  lcds[team].setCursor(0, row);
  
  int length = text.length();
  int offset = (20-length) / 2;

  // Add offset
  for (int i = 0; i < offset; i++) {
    lcds[team].print(" ");
  }
  // Print text
  lcds[team].print(text);
}
void displayText(String text, int row, boolean center, int team) {
  clearLine(row, team);

  if (text.length() <= 20) {

    if (center) centerPrintText(text, row, team);
    else lcds[team].print(text);
    
  } else if (text.length() <= 40) {

    String line1 = "";
    String line2 = "";

    if (text.charAt(19) != ' ') {
      int cutAt = 20;
      for (int i = 20; i > 0; i--) {
        if (text.charAt(i) == ' ') {
          cutAt = i;
          break;
        }
      }
      line1 = text.substring(0,cutAt);
      line2 = text.substring(cutAt,40);
    } else {
      line1 = text.substring(0,20);
      line2 = text.substring(20,40);
    }

    if (center)
      centerPrintText(line1, row, team),
      centerPrintText(line2, row+1, team);
    else
      lcds[team].setCursor(0,row), lcds[team].print(line1),
      lcds[team].setCursor(0,row+1), lcds[team].print(line2);
    
  }
}
void displayOnBoth(String text, int row, boolean center) {
  
}

void readyScreens() {
  lcds[0].begin(20, 4);
  lcds[0].setCursor(0, 0);
  lcds[1].begin(20,4);
  lcds[1].setCursor(0,0);
}





/* Led ring funcitions */

void colorWipe(uint32_t c, uint8_t wait) {
  /*for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }*/
}
void setRingColor(int r,int g,int b, int team, int ring) {
  for (int i = neos[team][ring][0]; i < neos[team][ring][1]; i++) {
    neo.setPixelColor(i, r,g,b);
  }
  neo.show();
}
void setTeamColor(int r,int g,int b, int team) {
  for (int i = neos[team][0][0]; i < neos[team][2][1]; i++) {
    setRingColor(r,g,b, team, i);
  }
}
void readyNeos() {
  // Define rings
  
  /*neos[0][0] = Adafruit_NeoPixel(16, neo1Apin, NEO_GRB + NEO_KHZ800);
  neos[0][1] = Adafruit_NeoPixel(16, neo1Bpin, NEO_GRB + NEO_KHZ800);
  neos[0][2] = Adafruit_NeoPixel(16, neo1Cpin, NEO_GRB + NEO_KHZ800);
  neos[1][0] = Adafruit_NeoPixel(16, neo2Apin, NEO_GRB + NEO_KHZ800);
  neos[1][1] = Adafruit_NeoPixel(16, neo2Bpin, NEO_GRB + NEO_KHZ800);
  neos[1][2] = Adafruit_NeoPixel(16, neo2Cpin, NEO_GRB + NEO_KHZ800);

  // Initiate and set brightness
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      neos[i][j].begin();
      neos[i][j].setBrightness(BRIGHTNESS);
      neos[i][j].show();
    }
  }*/
  
  neo.begin();
  neo.setBrightness(BRIGHTNESS);
  neo.show();
  
  neo2.begin();
  neo2.setBrightness(BRIGHTNESS);
  neo2.show();
}

