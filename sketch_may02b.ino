
#include "Pitches.h"
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

/* 
 * Questions 
 */
const int questionAmount = 14;
const String questions [14][5] = {
  {"Hvem er stats-#minister i Norge?#",                                "Siv Jensen",        "Erna Solberg",       "Jens Stoltenberg",  "2" },
  {"Hvor mange seter er#det pa Stortinget?#",                          "150",               "142",                "169",               "3" },
  {"Hvor mange testa-#menter er det i#Bibelen?#",                      "2",                 "3",                  "4",                 "1" },
  // {"Hvilke partier#sitter i regjering?#",                              "Hoyre og FrP",      "Hoyre, KrF og FrP",  "V, H, og FrP",    "1" },
  {"Hvilke partier gir#parlamentarisk#stotte til#regjeringen?#",       "Venstre", "KrF og FrP", "KrF og Venstre", "3" },
  {"Hvilken religion#tror pa#treenigheten?#",                          "Buddhismen", "Kristendommen", "Islam", "2" },
  {"Hva er divali?",                                                  "Lysfestival", "Nyttarsfeiring", "Blomsterfestival", "1" },
  // {"Hvilken type re-#gjering er den#sittende regjeringen#",            "Flertall", "Mindretall", "Liketall", "2" },
  {"Hvor hoy er#sperregrensen?#",                                      "4%", "5%", "6%", "1" },
  {"Hvem er leder#for Rodt?#",                                         "Trine Skei Grande#", "Bjornar Moxnes", "Jens Stoltenberg", "2" },
  {"Hvilken gruppe er#ikke kristne?#",                                  "Ortodokse", "Protestanter", "Bukharister", "3" },
  // {"Hvilket parti har#'Folk forst' som#slagord?#",                     "SV", "KrF", "Venstre", "3" },
  {"Hvem er leder#for KrF?#",                                          "Knut Arild Hareide#", "Karl I. Hagen", "Sylvi Listhaug", "1" },
  {"Hvilket parti er#tradisjonelt opptatt#av landbruk?#",              "Senterpartiet", "Arbeiderpartiet", "FrP", "1" },
  {"Hva er den#strengeste straffen#man kan fa i Norge?#",               "Dodsstraff", "18 ar fengsel", "21 ar fengsel", "3" },
  {"Hvem har den#lovgivende makt i#Norge?#",                           "Stortinget", "Regjeringen", "Domstolene", "1" },
  {"Hvem er Norges#finansminister?#",                                  "Jonas Gahr Store", "Siv Jensen", "Torbjorn Jagland", "2" },
  // {"Hvem er Norges#utenriksminister?#",                                "Sylvi Listhaug", "Borge Brende", "Hadia Tajik", "2" },
  // {"Hvem er FOR olje-#utvinning i Nordland,#Troms og Finnmark?#",      "Venstre", "FrP", "Rodt", "2" },
  /*
  {"Hvem har den#utovende makten i#Norge?", "Domstolene", "Stortinget", "Regjeringen", "3" },
  {"Hva heter samenes folkevalgte forsamling?", "Samestortinget", "Samelauget", "Sametinget", "3" },
  {"Hvem er leder for et departement?", "Statsminister", "Statsråd", "Departementsdirektør", "2" },
  {"Hvem er Norges formelle statsoverhode?", "Statsministeren", "Kongen", "Stortingspresidenten", "2" },
  {"Hvilken styreform har Norge?", "Demokrati", "Oligarki", "Diktatur", "1" },
  {"Hvilke internasjonalt samarbeid er Norge ikke medlem av?", "NATO", "EU", "FN", "2" },
  {"Hva er den øverste rettsinstansen i Norge?", "Høyesterett", "Tingretten", "Lagmannsretten", "1" },
  {"Hva er den strengeste straffen man kan få i Norge?", "Dødsstraff", "18 år fengsel", "21 år fengsel", "3" },
  {"Hvilken type demokrati har Norge?", "Direkte demokrati", "Indirekte demokrati", "Likhetsdemokrati", "2" },
  {"Hvilke politiske parti sitter ikke på Stortinget?", "Rødt", "MPG", "SV", "1" },
  {"Hvor mange folkeavstemninger har Norge hatt om EU-medlemskap?", "Ingen", "2", "4", "2" },
  {"Hvilken religion er ikke monoteistisk?", "Islam", "Jødedommen", "Hinduismen", "3" },
  {"Hvilken religion tror på treenigheten?", "Buddhismen", "Kristendommen", "Islam", "2" },
  {"Hvilken religion er bygget på de fem søylene?", "Islam", "Hinduismen", "Jødedommen", "1" },
  {"Toraen er en hellige tekst i hvilken religion?", "Islam", "Jødedommen", "Buddhismen", "2" },
  {"Hva kalles jødedommens gudshus?", "Moské", "Tempel", "Synagoge", "3" },
  {"Hvem leder bønnen i en moské?", "Presten", "Imamen", "Rabbiner", "2" },
  {"Hvem er øverste leder for den katolske kirke?", "Dalai Lama", "Paven", "Kardinalen", "2" },
  {"Hvilken religion feirer høytiden Divali?", "Buddhismen", "Hinduismen", "Jødedommen", "2" },
  {"Hvilken religion feirer høytiden Hanukka?", "Hinduismen", "Jødedommen", "Kristendommen", "2" },
  {"Rabbiner er en religiøs leder i hvilken religion?", "Buddhismen", "Islam", "Jødedommen", "3" },
  {"Hvilken religion feirer Eid?", "Islam", "Kristendommen", "Jødedommen", "1" },
  {"Hvorfor feirer kristne jul?", "Jesu død", "Jesu fødsel", "Jesu oppstandelse", "2" },
  {"Hvorfor feirer muslimer Mawlid?", "Muhammeds fødsel", "Muhammeds åpenbaring", "Muhammeds død", "1" },
  {"Hva er divali?", "Lysfestival", "Nyttårsfeiring", "Blomsterfestival", "1" },
  {"Hvilken religion feirer Bar / Bat Mitzva?", "Buddhismen", "Jødedommen", "Hinduismen", "2" },
  {"Hvilken religion feirer Vesak?", "Kristendommen", "Jødedommen", "Buddhismen", "3" },
  {"Hvilken religion er grunnlagt av Siddharta Gautama?", "Jødedommen", "Buddhismen", "Hinduismen", "2" },
  {"Talmud er en hellig tekst i hvilken religion?", "Jødedommen", "Hinduismen", "Islam", "1" },
  {"Hvilken religion anser ikke Jesus som en profet?", "Kristendommen", "Islam", "Hinduismen", "3" },
  {"Hvilken gruppe er ikke kristne?", "Ortodokse", "Protestanter", "Bukharister", "3" },
  {"Hvilken religion har flest tilhengere?", "Islam", "Kristendom", "Hinduismen", "2" },
  {"Hvem tror ikke på reinkarnasjon?", "Buddhister", "Hinduister", "Kristne", "3" },
  {"Koranen er en hellig tekst i hvilken religion?", "Islam", "Jødedommen", "Buddhismen", "1" },
  {"Hvor mange testamenter er det i Bibelen?", "2", "3", "4", "2" },
  {"Hva er ikke en jødisk høytid?", "Hannuka", "Rosj Hasjaná", "Olsok", "3" },
  */
};



/* Displays */
LiquidCrystal lcds[2] = {LiquidCrystal(33, 31, 29, 27, 25, 23), LiquidCrystal(45, 43, 41, 39, 37, 35)};

// arrow right
byte newChars[3][8] = {
  {
    B00000, B00100, B00010, B11111,
    B00010, B00100, B00000, B00000 
  },
  {
    B00000, B00100, B00010, B11111,
    B00010, B00100, B00000, B00000 
  },
  {
    B00000, B00100, B00010, B11111,
    B00010, B00100, B00000, B00000 
  },
};

/* Led rings */
const int 
  neo1pin = 11,
  neo2pin = 12;
const int BRIGHTNESS = 50;
const int neoPixels[3][2] = {
  {0, 16},
  {16, 32},
  {32, 48},
};
Adafruit_NeoPixel neos[2] = { Adafruit_NeoPixel(48, neo1pin, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(48, neo2pin, NEO_GRB + NEO_KHZ800) };


/* Globals */
boolean shouldRun;
boolean printInfo;
boolean waitingForTeamsToJoin;
boolean teamJoined;
unsigned long curTime;

const int piezo = 52;
const int
  but1A = 24,
  but1B = 26,
  but1C = 28,
  but2A = 30,
  but2B = 32,
  but2C = 10;
const int playBut = 9;
const int buttonDelay = 1000;
const int questionTime = 25000;
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
int neoPoints;
int roundPoints[2];
int points[2];
int team1Answer, team2Answer;

boolean displayedScores;





/*
 * Main
 */

void setup() {
  readyScreens();
  Serial.begin(9600);

  setQuestion(0);
  resetRoundPoints();
  shouldRun = false;
  printInfo = true;
  waitingForTeamsToJoin = true;
  teamJoined = false;
  
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
  pinMode(playBut, INPUT_PULLUP);

  displayOnBoth("Starter opp!", 1, true);

  readyNeos();
}
void loop() {

  curTime = millis();

  /* 
   * Waiting for teams to join and start 
   */
  if (printInfo) {
    displayOnBoth("Trykk for a bli med!", 1, true);
    displayOnBoth("Og oppa for a starte", 2, true);

    lcds[0].setCursor(0,0);
    lcds[0].write(byte(0));
    
    setTeamColor(0,0,255, 0);
    setTeamColor(0,0,255, 1);
    
    printInfo = false;
  }
  if (waitingForTeamsToJoin) {
    //  Check for team 1
    if (!digitalRead(but1A) || !digitalRead(but1B) || !digitalRead(but1C)) {
      // team 1 has joined
      teamJoined = true;
      setTeamColor(255,255,255, 0);
      clearLine(2, 0);
      displayText("Du er med!", 1, true, 0);
      displayText("Start: trykk oppa", 2, true, 0);
      tone(piezo, NOTE_C4, 150);
    }
    if (!digitalRead(but2A) || !digitalRead(but2B) || !digitalRead(but2C)) {
      // team 2 has joined
      teamJoined = true;
      setTeamColor(255,255,255, 1);
      clearLine(2, 1);
      displayText("Du er med!", 1, true, 1);
      displayText("Start: trykk oppa", 2, true, 1);
      tone(piezo, NOTE_C4, 150);
    }

    // A team has joined
    if (teamJoined) {
      if (!digitalRead(playBut)) {
        // Start
        waitingForTeamsToJoin = false;
        prevTime = curTime;
        shouldRun = true;
        tone(piezo, NOTE_F3, 250);
      }
    }
  }
  


  /*
   * Playing
   */
  if (shouldRun) {

    curPoints = (questionTime - (curTime - prevTime)) / 10;
    // neoPoints = ((curPoints * 16) / questionTime);
    neoPoints = ((((curPoints) - 0) * 16) / 1191) + 0;

    /* Make leds reflect time left
    for (int i = neoPoints; i < 0; i--) {
      neos[0].setPixelColor(neoPoints, 255,255,255);
      neos[1].setPixelColor(neoPoints, 255,255,255);
    }
    
    
    if (!team1HasAnswered && !team2HasAnswered) {
      neos[0].setPixelColor(neoPoints, 255,255,255);
      neos[0].setPixelColor(neoPoints, 255,255,255);
      neos[0].show();
      neos[1].show();
    }
    */
    
  
    // If next question exists
    if (hasNextQuestion()) {
  
      // If question has not been printed, print it
      if (printNextQuestion) {
        setTeamColor(0,0,255, 0);
        setTeamColor(0,0,255, 1);
        
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
        resetRoundPoints();
  
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
        lcds[w].print("Gratulerer");
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
        clearDisplays();
        for (int i = 0; i < 2; i++) {
          lcds[i].setCursor(6, 1);
          lcds[i].print("Uavgjort");
          lcds[i].setCursor(5, 2);
          lcds[i].print(points[i]);
          lcds[i].print(" poeng!");
        }
      }
      displayedScores = true;
      
    }


    // Reset if is finished
    if (!digitalRead(playBut) && !hasNextQuestion()) {
      nextQuestionId = 0;
      questionCount = 0;
      setQuestion(0);
      resetRoundPoints();
      points[0] = 0;
      points[1] = 0;
      shouldRun = false;
      printInfo = true;
      waitingForTeamsToJoin = true;
      teamJoined = false;
        
      printNextQuestion = true;
      teamsAnswered = 0;
      questionIsAnswered = false;
      displayedScores = false; 
    }

  }
}





/*
 * Resetting data
 */
void resetRoundPoints() {
  roundPoints[0] = 0;
  roundPoints[1] = 0;
}
void resetForNextLoop() {
  teamsAnswered = 0;
  questionIsAnswered = false;
  team1HasAnswered = false;
  team2HasAnswered = false;
  team1Answer = -1;
  team2Answer = -1;

  questionCount++;
  nextQuestionId += 1;
  nextQuestion();

  prevTime = curTime;
}




/*
 * Q and A
 */
boolean hasWaited(unsigned long curTime, int delayTime) {
  if ((curTime - prevTime) >= delayTime) {
    prevTime = curTime;
    return true;
  }
  return false;
}

void printQuestion() {
  
  // Print to monitor
  Serial.print("\nSporsmal ");
  Serial.print((questionCount + 1));
  Serial.println(":");
  Serial.println(curQuestion[0]);
  Serial.println("A: " + curQuestion[1] + ". B: " + curQuestion[2] + ". C: " + curQuestion[3]);
  Serial.println();

  clearDisplays();
  
  String question = "Sporsmal ";
  question = question + (questionCount + 1);
  displayOnBoth(question, 1, true);
  
  delay(2000);
  
  clearDisplays();
  displayOnBoth(curQuestion[0], 0, false);
  
  delay(4000);

  clearDisplays();
  displayOnBoth("A: " + curQuestion[1], 0, false);
  displayOnBoth("B: " + curQuestion[2], 1, false);
  displayOnBoth("C: " + curQuestion[3], 2, false);
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

  setRingColor(255,255,255, team, answer, 1);
  
  int correctAnswer = getAnswerId();
  correctAnswer--;
  
  boolean isCorrect = (answer == correctAnswer);
  
  if (isCorrect) {
    roundPoints[team] = curPoints;
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
      team1Answer = answer;
      break;
    case 1:
      team2HasAnswered = true;
      team2Answer = answer;
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
    else if (!digitalRead(but1B)) {
      answerQuestion(1, 0);
    }
    else if (!digitalRead(but1C)) {
      answerQuestion(2, 0);
    }
    
    if (!digitalRead(but1A) || !digitalRead(but1B) || !digitalRead(but1C)) {
      tone(piezo, NOTE_C4, 150);
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
    
    if (!digitalRead(but2A) || !digitalRead(but2B) || !digitalRead(but2C)) {
      tone(piezo, NOTE_C4, 150);
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




/*
 * LCD printing
 */
void readyScreens() {
  lcds[0].begin(20, 4);
  lcds[0].setCursor(0, 0);
  lcds[1].begin(20,4);
  lcds[1].setCursor(0,0);

  for (int i = 0; i < 2; i++) {
    lcds[i].begin(20, 4);
    lcds[i].setCursor(0, 0);
    
    for (int j = 0; j < 3; j++) {
      lcds[i].createChar(j, newChars[j]);
    }
  }
}
void clearLine(int row, int team) {
  lcds[team].setCursor(0, row);
  lcds[team].print("                    ");
  lcds[team].setCursor(0, row);
}
void clearDisplays() {
  lcds[0].clear();
  lcds[1].clear();
}
void displayScores() {
  clearDisplays();

  String team1Points = " poeng",
         team2Points = " poeng";

  int correctAnswer = curQuestion[4].toInt();
  correctAnswer--;

  // Set team colors
  for (int i = 0; i < 2; i++) {
    setTeamColor(255,0,0, i);
  }
  

  /*
   * Alle ringar gront viss rett, rodt viss ikkje (prikka gront rundt det rette svaret)
   */
  if (team1HasAnswered) {
    if (team1Answer == correctAnswer) {
      // Rett svar
      setTeamColor(0,255,0, 0);
      displayText("Rett svar!", 1, true, 0);
    } else {
      // Feil svar
      setRingColor(0,0,0,   0, correctAnswer, 1);
      setRingColor(0,255,0, 0, correctAnswer, 2);
      displayText("Feil svar!", 1, true, 0);
    }
  }
  if (team2HasAnswered) {
    if (team2Answer == correctAnswer) {
      // Rett svar
      setTeamColor(0,255,0, 1);
      displayText("Rett svar!", 1, true, 1);
    } else {
      // Feil svar
      setRingColor(0,0,0,   1, correctAnswer, 1);
      setRingColor(0,255,0, 1, correctAnswer, 2);
      displayText("Feil svar!", 1, true, 1);
    }
  }
  
  team1Points = (roundPoints[0]) + team1Points;
  team2Points = (roundPoints[1]) + team2Points;

  displayText(team1Points, 2, true, 0);
  displayText(team2Points, 2, true, 1);
  
  Serial.print("Lag 1: ");
  Serial.print(points[0]);
  Serial.print(". Lag 2: ");
  Serial.println(points[1]);
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

  if (center) { 
    centerPrintText(text, row, team); 
    return;
  }
  
  int maxLines = 4;
  int maxLength = 20;
  
  if (text.length() <= maxLength) {

    lcds[team].setCursor(0, row);
    lcds[team].print(text);
      
  } else {

    int curLine = row;
    String curLineText = "";
    int cutStartPos = 0;
    int cutStopPos= 0;
    int lines = 0;

    String printLines[4];

    for (int i = 0; i < 80; i++) {
      if (text.charAt(i) == '#') {
          
        cutStopPos = i;
        curLineText = text.substring(cutStartPos, cutStopPos);
        cutStartPos = (cutStopPos+1);
        
        printLines[lines] = curLineText;
        
        lines++;
      }
    }

    for (int i = 0; i < lines; i++) {
      lcds[team].setCursor(0, (row+i));
      lcds[team].print(printLines[i]);
    }

  }
}
void displayOnBoth(String text, int row, boolean center) {
  for (int i = 0; i < 2; i++) {
    displayText(text, row, center, i);
  }
}




/* 
 * LED rings
 */
void colorWipe(uint32_t c, uint8_t wait) {
  /*for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }*/
}
void setRingColor(int r,int g,int b, int team, int ring, int interval) {
  for (int i = neoPixels[ring][0]; i < neoPixels[ring][1]; i += interval) {
    neos[team].setPixelColor(i, r,g,b);
  }
  neos[team].show();
}
void setTeamColor(int r,int g,int b, int team) {
  for (int i = 0; i < 3; i++) {
    setRingColor(r,g,b, team, i, 1);
  }
}
void readyNeos() {
  // Define rings
  for (int i = 0; i < 2; i++) {
    neos[i].begin();
    neos[i].setBrightness(BRIGHTNESS);
    neos[i].show();
  }
}




/*
 * Misc
 */
int roundUp(int toRound) {
  return (10 - toRound % 10) + toRound;
}
int roundDown(int toRound) {
  return toRound - toRound % 10;
}


