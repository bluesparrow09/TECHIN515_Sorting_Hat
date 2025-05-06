# Sorting Hat - TECHIN515 Lab 3

## Overview
This project implements a "Sorting Hat" prototype that classifies users into Hogwarts houses based on their responses to quiz questions.  
The system runs on an ESP32 and uses a small machine learning model trained on synthetic survey data.

## Project Components
- ESP32 Dev Board
- 4 Push Buttons for answering questions
- OLED Display to show questions and results

## Implementation Notes
- Generated a synthetic dataset to simulate user quiz responses.
- Trained a Decision Tree Classifier using the generated data.
- Exported the trained model into C++ format (`sorting_hat_model.h`) for deployment on ESP32.
- Programmed the ESP32 to:
  - Display questions and options on an OLED screen
  - Collect user answers through button inputs
  - Predict and display the assigned Hogwarts house

During training:
- With only 10 entries, the model accuracy was about 0%.
- With 50 entries, the model accuracy improved to around 30%.
- With 100 entries, the model achieved 100% accuracy.
This highlights the importance of having enough and varied training data.

## Discussion

### Observations
During playtesting, I noticed that pressing and holding a button for slightly too long would cause the system to skip multiple questions at once.  
This happened because the code continuously detected the button press without waiting for release.

### Improvements
- Add button debounce logic to prevent accidental multiple inputs.
- Use real user responses instead of synthetic data to improve model generalization.
- Fine-tune decision tree parameters (e.g., max depth) if needed.

### Hardware Enhancement Ideas
- Add sound feedback for button presses.
- Use capacitive touch sensors for a smoother experience.

### Model Considerations
For the current setup, the decision tree is appropriate due to the small number of features and clear decision boundaries.  
If adding more complex inputs like sensors, I would consider using a Random Forest or a simple Neural Network for better performance.
