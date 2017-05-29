#include "Pitches.h"
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

/* Questions */
const int questionAmount = 10;
const int questionTotalAmount = 30;
const String questions [questionTotalAmount][5] = {
  {"Hvem er stats-#minister i Norge?#",                                "Siv Jensen",        "Erna Solberg",       "Jens Stoltenberg",  "2" },
  {"Hvor mange seter er#det pa Stortinget?#",                          "150",               "142",                "169",               "3" },
  {"Hvor mange testa-#menter er det i#Bibelen?#",                      "2",                 "3",                  "4",                 "1" },
  {"Hvilke partier#sitter i regjering?#",                              "Hoyre og FrP",      "Hoyre, KrF og FrP",  "V, H, og FrP",    "1" },
  {"Hvilke partier gir#parlamentarisk#stotte til#regjeringen?#",       "Venstre", "KrF og FrP", "KrF og Venstre", "3" },
  {"Hvilken religion#tror pa#treenigheten?#",                          "Buddhismen", "Kristendommen", "Islam", "2" },
  {"Hva er divali?",                                                   "Lysfestival", "Nyttarsfeiring", "Blomsterfestival", "1" },
  {"Hvilken type re-#gjering er den#sittende regjeringen#",            "Flertall", "Mindretall", "Liketall", "2" },
  {"Hvor hoy er#sperregrensen?#",                                      "4%", "5%", "6%", "1" },
  {"Hvem er leder#for Rodt?#",                                         "Trine Skei Grande#", "Bjornar Moxnes", "Jens Stoltenberg", "2" },
  
  {"Hvilken gruppe er#ikke kristne?#",                                 "Ortodokse", "Protestanter", "Bukharister", "3" },
  {"Hvilket parti har#'Folk forst' som#slagord?#",                     "SV", "KrF", "Venstre", "3" },
  {"Hvem er leder#for KrF?#",                                          "Knut Arild Hareide#", "Karl I. Hagen", "Sylvi Listhaug", "1" },
  {"Hvilket parti er#tradisjonelt opptatt#av landbruk?#",              "Senterpartiet", "Arbeiderpartiet", "FrP", "1" },
  {"Hva er den#strengeste straffen#man kan fa i Norge?#",              "Dodsstraff", "18 ar fengsel", "21 ar fengsel", "3" },
  {"Hvem har den#lovgivende makt i#Norge?#",                           "Stortinget", "Regjeringen", "Domstolene", "1" },
  {"Hvem er Norges#finansminister?#",                                  "Jonas Gahr Store", "Siv Jensen", "Torbjorn Jagland", "2" },
  {"Hvem er Norges#utenriksminister?#",                                "Sylvi Listhaug", "Borge Brende", "Hadia Tajik", "2" },
  {"Hvem er FOR olje-#utvinning i Nordland#Troms og Finnmark?#",       "Venstre", "FrP", "Rodt", "2" },
  {"Toraen er en hellige#tekst i hvilken#religion?#",                  "Islam", "Jodedommen", "Buddhismen", "2" },
  
  {"Hvem har den#utovende makten i#Norge?#",                           "Domstolene", "Stortinget", "Regjeringen", "3" },
  {"Hva heter samenes#folkevalgte for-#samling?#",                     "Samestortinget", "Samelauget", "Sametinget", "3" },
  {"Hvem er leder for#et departement?#",                               "Statsminister", "Statsrad", "Depts.direktør", "2" },
  {"Hvem er Norges#formelle stats-#overhode?#",                        "Statsministeren", "Kongen", "Stortings-#   presidenten#", "2" },
  {"Hvilken styreform#har Norge?#",                                    "Demokrati", "Oligarki", "Diktatur", "1" },
  {"Hvilke internasjonale#samarbeid er Norge#ikke medlem av?#",        "NATO", "EU", "FN", "2" },
  {"Hva er den#overste retts-#instansen i Norge?#",                    "Hoyesterett", "Tingretten", "Lagmannsretten", "1" },
  {"Hva er den streng-#este straffen man#kan fa i Norge?#",            "Dodsstraff", "18 ar fengsel", "21 ar fengsel", "3" },
  {"Hvilken type#demokrati har Norge?#",                               "Direkte demokr.", "Indirekte demokr.", "Likhetsdemokr.", "2" },
  {"Hvilke politiske#parti sitter ikke#pa Stortinget?#",               "Rodt", "MPG", "SV", "1" },
  
/*
  {"Hvor mange folke-#avstemninger har#Norge hatt om#EU-medlemskap?#",  "Ingen", "2", "4", "2" },
  {"Hvilken religion er#ikke monoteistisk?#",                           "Islam", "Jodedommen", "Hinduismen", "3" },
  {"Hvilken religion#tror pa#treenigheten?#",                           "Buddhismen", "Kristendommen", "Islam", "2" },
  {"Hvilken religion er#bygget på de#fem soylene?#",                    "Islam", "Hinduismen", "Jodedommen", "1" },
  {"Hva kalles jode-#dommens gudshus?#",                                  "Moske", "Tempel", "Synagoge", "3" },
  {"Hvem leder bonnen#i en moske?#",                                    "Presten", "Imamen", "Rabbiner", "2" },
  {"Hvem er overste#leder for den#katolske kirke?#",                    "Dalai Lama", "Paven", "Kardinalen", "2" },
  {"Hvilken religion#feirer hoytiden#Divali?#",                         "Buddhismen", "Hinduismen", "Jodedommen", "2" },
  {"Hvilken religion#feirer hoytiden#Hanukka?#",                        "Hinduismen", "Jodedommen", "Kristendommen", "2" },
  {"Rabbiner er en#religios leder i#hvilken religion?#",                "Buddhismen", "Islam", "Jodedommen", "3" },
  /*
  {"Hvilken religion#feirer Eid?#",                                     "Islam", "Kristendommen", "Jodedommen", "1" },
  {"Hvorfor feirer#kristne jul?#",                                      "Jesu dod", "Jesu fodsel", "Jesu oppstandelse", "2" },
  // {"Hvorfor feirer#muslimer Mawlid?#",                                  "Muhammeds fodsel", "Muhammeds apenbaring", "Muhammeds død", "1" },
  {"Hvem tror ikke#pa reinkarnasjon?#",                                 "Buddhister", "Hinduister", "Kristne", "3" },
  {"Hvilken religion#feirer Bar/Bat#Mitzva?#",                          "Buddhismen", "Jodedommen", "Hinduismen", "2" },
  {"Hvilken religion#feirer Vesak?#",                                   "Kristendommen", "Jodedommen", "Buddhismen", "3" },
  {"Hvilken religion er#grunnlagt av#Siddharta Gautama?#",              "Jodedommen", "Buddhismen", "Hinduismen", "2" },
  {"Talmud er en hellig#tekst i hvilken#religion?#",                    "Jodedommen", "Hinduismen", "Islam", "1" },
  {"Hvilken religion#anser ikke Jesus#som en profet?#",                 "Kristendommen", "Islam", "Hinduismen", "3" },
  {"Hvilken religion har#flest tilhengere?#",                           "Islam", "Kristendom", "Hinduismen", "2" },
  {"Koranen er en#hellig tekst i#hvilken religion?#",                   "Islam", "Jodedommen", "Buddhismen", "1" },

  /*
  {"Hvem tror ikke på reinkarnasjon?", "Buddhister", "Hinduister", "Kristne", "3" },
  {"Hva er ikke en jødisk høytid?", "Hannuka", "Rosj Hasjaná", "Olsok", "3" },
  */
};



/* Displays */
LiquidCrystal lcds[2] = {LiquidCrystal(33, 31, 29, 27, 25, 23), LiquidCrystal(45, 43, 41, 39, 37, 35)};

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

/* General */
boolean shouldRun;
boolean printInfo;
boolean waitingForTeamsToJoin;
boolean teamJoined;
unsigned long curTime;
boolean displayedScores;

/* Pins */
const int piezo = 52;
const int playBut = 9;
const int 
  but1A = 24, but2A = 30,
  but1B = 26, but2B = 32,
  but1C = 28, but2C = 10;

/* Timing */
const int buttonDelay = 1000;
const int questionTime = 25000;
const int coolDownTime = 3000;
unsigned long prevTime = 0;

/* Question */
String curQuestion[5];
boolean printNextQuestion;
int questionCount = 0;
int curQuestionId = 0;

/* Answers */
int team1Answer,
    team2Answer;
boolean team1HasAnswered = false;
boolean team2HasAnswered = false;
boolean questionIsAnswered;

/* Points */
int curPoints;         // Current points available
int roundPoints[2];    // Team's points in a round
int points[2];         // Team's total points




/*
 * Main
 */

void setup() {
  /* Prepare LCD displays */
  readyScreens();
  Serial.begin(9600);

  /* Set question, prepare question data */
  setQuestion(0);
  resetRoundPoints();

  /* Make main loop wait for user input */
  shouldRun = false;
  printInfo = true;
  waitingForTeamsToJoin = true;
  teamJoined = false;

  /* Dont print questions until user is ready */
  printNextQuestion = true;
  questionIsAnswered = false;
  displayedScores = false;

  /* Prepare inputs */
  pinMode(but1A, INPUT_PULLUP);
  pinMode(but1B, INPUT_PULLUP);
  pinMode(but1C, INPUT_PULLUP);
  pinMode(but2A, INPUT_PULLUP);
  pinMode(but2B, INPUT_PULLUP);
  pinMode(but2C, INPUT_PULLUP);
  pinMode(playBut, INPUT_PULLUP);

  /* Display loading message */
  displayOnBoth("Starter opp!", 1, true);

  /* Prepare LED rings */
  readyNeos();
}
void loop() {

  // Update time
  curTime = millis();


  /* 
   * Waiting for teams to join and start 
   */
  if (printInfo) {
    /* Instruct the user in how to start */
    displayOnBoth("Trykk for a bli med!", 1, true);
    displayOnBoth("Og oppa for a starte", 2, true);

    /* Set each teams led rings to blue (standard) */
    setTeamColor(0,0,255, 0);
    setTeamColor(0,0,255, 1);

    /* Dont print this again */
    printInfo = false;
  }
  if (waitingForTeamsToJoin) {
    /* Check for teams */
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

    /* If a team has joined */
    if (teamJoined) {
      if (!digitalRead(playBut)) {
        // Start, if they push the play button
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

    /* Currently available points */
    curPoints = (questionTime - (curTime - prevTime)) / 10;
  
    /* If next question exists */
    if (hasNextQuestion()) {
  
      /* If question has not been printed, print it */
      if (printNextQuestion) {
        // Set team colors to blue (standard)
        setTeamColor(0,0,255, 0);
        setTeamColor(0,0,255, 1);
        printQuestion();
        
        printNextQuestion = false; // Dont print it again
      }

      
  
      /* Listen for answers */
      listenForAnswers();

      
  
      /* If time is up, or question has been answered by both teams */
      if (hasWaited(curTime, questionTime) || questionIsAnswered) {
  
        /* Display scores */
        displayScores();
  
        /* Reset for next round */
        resetForNextLoop();
        resetRoundPoints();
  
        /* If there is a next question, display it */
        if (hasNextQuestion()) {
          delay(coolDownTime);
          printNextQuestion = true;
        }
  
      }
  
    }
  
  
    /* If no more questions available, and scores have not been displayed */
    if (!hasNextQuestion() && !displayedScores) {
  
      /* Display scores */
      if (getLeadingTeam() >= 0) {
        // If there is a winner, define winner and loser
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
      // Scores have now been displayed
      displayedScores = true;
      
    }

    /* Reset if current game is finished, on user input */
    if (!digitalRead(playBut) && !hasNextQuestion()) {
      
      if (curQuestionId < questionTotalAmount) {
        // There are more questions available
        setQuestion(curQuestionId);
      } else {
        // No more questions available; restart 
        curQuestionId = 0;
        setQuestion(0);
      }

      /* Restart and reset data */
      questionCount = 0;
      resetRoundPoints();
      points[0] = 0;
      points[1] = 0;

      /* Wait for user input to start */
      shouldRun = false;
      printInfo = true;
      waitingForTeamsToJoin = true;
      teamJoined = false;

      printNextQuestion = true;
      questionIsAnswered = false;
      displayedScores = false;
    }

  }
  
}





/*
 * Resetting data
 */
void resetRoundPoints() {
  // Resets each teams points for each round
  roundPoints[0] = 0;
  roundPoints[1] = 0;
}
void resetForNextLoop() {
  // Resets data for next round
  questionIsAnswered = false;
  team1HasAnswered = false;
  team2HasAnswered = false;
  team1Answer = -1;
  team2Answer = -1;

  // Get next question
  questionCount++;
  nextQuestion();

  // Reset time and points
  prevTime = curTime;
}




/*
 * Q and A
 */
boolean hasWaited(unsigned long curTime, int delayTime) {
  // Returns true if user has waited [delayTime] amount of time
  if ((curTime - prevTime) >= delayTime) {
    prevTime = curTime;
    return true;
  }
  return false;
}

void printQuestion() {
  // Print to monitor for debugging
  Serial.print("\nSporsmal ");
  Serial.print((questionCount + 1));
  Serial.println(":");
  Serial.println(curQuestion[0]);
  Serial.println("A: " + curQuestion[1] + ". B: " + curQuestion[2] + ". C: " + curQuestion[3]);
  Serial.println();

  // Print question number
  clearDisplays();
  String question = "Sporsmal ";
  question = question + (questionCount + 1);
  displayOnBoth(question, 1, true);
  
  delay(2000);

  // Print the question
  clearDisplays();
  displayOnBoth(curQuestion[0], 0, false);
  
  delay(4000);

  // Print the alternatives
  clearDisplays();
  displayOnBoth("A: " + curQuestion[1], 0, false);
  displayOnBoth("B: " + curQuestion[2], 1, false);
  displayOnBoth("C: " + curQuestion[3], 2, false);
}
void setQuestion(int id) {
  // Sets the current question, with alternatives
  for (int i = 0; i < 5; i++) {
    curQuestion[i] = questions[id][i];
  }
}
void nextQuestion() {
  // Sets a new (the next) question
  curQuestionId++;
  setQuestion(curQuestionId);
}
boolean hasNextQuestion() {
  // Returns true if there is another question available
  if (questionCount < questionAmount) return true;
  return false;
}
int getAnswerId() {
  // Returns which alternative is correct
  return curQuestion[4].toInt();
}

boolean answerQuestion(int answer, int team) {
  /* Answers a question */

  // Set the chosen alternative's color to white
  setRingColor(255,255,255, team, answer, 1);

  // Get the correct answer
  int correctAnswer = getAnswerId();
  correctAnswer--;

  // User is correct if their answer equals the correct answer
  boolean isCorrect = (answer == correctAnswer);

  // Is user answered correctly
  if (isCorrect) {
    // Award them points (both current round, and total)
    roundPoints[team] = curPoints;
    points[team] += curPoints;

    // Print to monitor for debugging
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
    // When a team answers, update their answer status
    case 0:
      team1HasAnswered = true;
      team1Answer = answer;
      break;
    case 1:
      team2HasAnswered = true;
      team2Answer = answer;
      break;
  }

  return isCorrect;
}
void listenForAnswers() {
  /* Listens for answers from the user */
  
  /* Team 1 */
  if (!team1HasAnswered) {
    if (!digitalRead(but1A)) {
      answerQuestion(0, 0);
      tone(piezo, NOTE_C4, 150);
    }
    else if (!digitalRead(but1B)) {
      answerQuestion(1, 0);
      tone(piezo, NOTE_C4, 150);
    }
    else if (!digitalRead(but1C)) {
      answerQuestion(2, 0);
      tone(piezo, NOTE_C4, 150);
    }
  }

  /* Team 2 */
  if (!team2HasAnswered) {
    if (!digitalRead(but2A)) {
      answerQuestion(0, 1);
      tone(piezo, NOTE_C4, 150);
    }
    else if (!digitalRead(but2B)) {
      answerQuestion(1, 1);
      tone(piezo, NOTE_C4, 150);
    }
    else if (!digitalRead(but2C)) {
      answerQuestion(2, 1);
      tone(piezo, NOTE_C4, 150);
    }
  }

  /* If both teams have answered, question is considered answered/finished */
  if (team1HasAnswered && team2HasAnswered) questionIsAnswered = true;
}
int getLeadingTeam() {
  // Returns the id of the leading team
  // negative if there is a draw
  if (points[0] > points[1]) return 0;
  else if (points[0] < points[1]) return 1;
  else return -1;
}




/*
 * LCD printing
 */
void readyScreens() {
  // Prepares displays
  for (int i = 0; i < 2; i++) {
    lcds[i].begin(20, 4);
    lcds[i].setCursor(0, 0);
  }
}
void clearLine(int row, int team) {
  // Clears a chosen line on the display
  lcds[team].setCursor(0, row);
  lcds[team].print("                    ");
  lcds[team].setCursor(0, row);
}
void clearDisplays() {
  // Clears all displays
  lcds[0].clear();
  lcds[1].clear();
}
void displayScores() {
  // Displays scores
  clearDisplays();

  String team1Points = " poeng",
         team2Points = " poeng";

  // Get correct answer
  int correctAnswer = curQuestion[4].toInt();
  correctAnswer--;

  /* TODO: remove this?
  // Set team colors
  for (int i = 0; i < 2; i++) {
    setTeamColor(255,0,0, i);
  }
  */

  /*
   * All rings are green if correct, red if not (dotted green around the correct answer)
   */
  if (team1HasAnswered) {
    if (team1Answer == correctAnswer) {
      // Correct answer
      setTeamColor(0,255,0, 0);
      displayText("Rett svar!", 1, true, 0);
    } else {
      // Wrong answer
      // Make correct answer dotted green
      setRingColor(0,0,0,   0, correctAnswer, 1);
      setRingColor(0,255,0, 0, correctAnswer, 2);
      displayText("Feil svar!", 1, true, 0);
    }
  }
  if (team2HasAnswered) {
    if (team2Answer == correctAnswer) {
      // Correct answer
      setTeamColor(0,255,0, 1);
      displayText("Rett svar!", 1, true, 1);
    } else {
      // Wrong answer
      // Make correct answer dotted green
      setRingColor(0,0,0,   1, correctAnswer, 1);
      setRingColor(0,255,0, 1, correctAnswer, 2);
      displayText("Feil svar!", 1, true, 1);
    }
  }

  // Display how many points each team got
  team1Points = (roundPoints[0]) + team1Points;
  team2Points = (roundPoints[1]) + team2Points;
  displayText(team1Points, 2, true, 0);
  displayText(team2Points, 2, true, 1);

  // Print to monitor for debugging
  Serial.print("Lag 1: ");
  Serial.print(points[0]);
  Serial.print(". Lag 2: ");
  Serial.println(points[1]);
}
void centerPrintText(String text, int row, int team) {
  // Prints text on lcd, centered
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
    // Centered text must be under 20 characters
    centerPrintText(text, row, team); 
    return;
  }

  // Define the LCD's constraints
  int maxLines = 4;
  int maxLength = 20;
  
  if (text.length() <= maxLength) {
    // If text is under 20 characters long, print it
    lcds[team].setCursor(0, row);
    lcds[team].print(text);
      
  } else {
    // If text is more than 20 characters long
    
    String curLineText = "";
    int cutStartPos = 0;
    int cutStopPos= 0;
    int lines = 0;

    String printLines[4];

    // Create printable sentence
    for (int i = 0; i < 80; i++) {
      if (text.charAt(i) == '#') {
          
        cutStopPos = i;
        curLineText = text.substring(cutStartPos, cutStopPos);
        cutStartPos = (cutStopPos+1);

        // Add to final sentence
        printLines[lines] = curLineText;
        
        lines++;
      }
    }

    // Print final sentence
    for (int i = 0; i < lines; i++) {
      lcds[team].setCursor(0, (row+i));
      lcds[team].print(printLines[i]);
    }

  }
}
void displayOnBoth(String text, int row, boolean center) {
  // Displays text on both lcds
  for (int i = 0; i < 2; i++) {
    displayText(text, row, center, i);
  }
}




/* 
 * LED rings
 */
void setRingColor(int r,int g,int b, int team, int ring, int interval) {
  // Sets a color on a [team]'s chosen [ring]. Interval defines if it is each pixel, or every other, etc
  for (int i = neoPixels[ring][0]; i < neoPixels[ring][1]; i += interval) {
    neos[team].setPixelColor(i, r,g,b);
  }
  neos[team].show();
}
void setTeamColor(int r,int g,int b, int team) {
  // Sets the ring color on all of a [team]'s rings
  for (int i = 0; i < 3; i++) {
    setRingColor(r,g,b, team, i, 1);
  }
}
void readyNeos() {
  // Initialize and set brightness of LED rings
  for (int i = 0; i < 2; i++) {
    neos[i].begin();
    neos[i].setBrightness(BRIGHTNESS);
    neos[i].show();
  }
}

