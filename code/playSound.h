void playStartupSound() {
  int melody[] = {660, 880};
  int noteDurations[] = {100, 150};

  for (int i = 0; i < 2; i++) {
    tone(BUZZER_PIN, melody[i], noteDurations[i]);
    delay(noteDurations[i]);
  }

  noTone(BUZZER_PIN);
}

void playButtonClickSound() {
  tone(BUZZER_PIN, 1000, 200);
  delay(200);
}

void playMorseDotSound() {
  tone(BUZZER_PIN, 1000);
}

void offSound() {
  noTone(BUZZER_PIN);
}