# Overview

This project implements a "Sorting Hat" prototype that classifies users into Hogwarts houses based on their responses to a series of questions.  
The system runs on an ESP32 and uses a small machine learning model trained on synthetic survey data.

# Project Components
- ESP32 Dev Board
- 4 Push Buttons for answering questions
- OLED Display to show questions and results

# My Work
- Generated a synthetic dataset to simulate user quiz responses.
- Trained a Decision Tree Classifier using the generated data.
- Exported the trained model into C++ format (`sorting_hat_model.h`) for deployment on ESP32.
- Programmed the ESP32 to:
  - Display questions and options on an OLED screen
  - Collect user answers through button inputs
  - Predict and display the assigned Hogwarts house
    
# Video
  https://drive.google.com/file/d/1iGcjHwUeRmm7t4k_P9UMDjE8TeTTxWr3/view?usp=sharing
## Discussion

### Are all 10 questions important?

During testing, I observed that the sorting hat depends on the answers to all 10 questions to make an accurate classification.  
However, if necessary to improve user experience and shorten interaction time, I might consider removing questions that are redundant or similar in theme.  
For example, questions related to favorite subject and dream career seem to slightly overlap in evaluating ambition and interests. Removing one of them could simplify the process without majorly affecting the classification.

### Observed issues during playtesting

One issue I encountered was that when pressing a button to answer a question, the system sometimes skipped multiple questions at once.  
Upon investigation, I realized this was because the system continuously registered the button being held down as multiple button presses.  
This happened because my `checkButtons()` function did not properly debounce or wait for the button to be released after a press.

**Root cause:**  
- The code was detecting a press every time through the loop without waiting for the button to be released.  
- As a result, holding a button even slightly too long would cause multiple "answers" to be recorded in rapid succession.

**Potential fix:**  
- Modify the code to detect only the transition from unpressed to pressed (button down event).
- Wait until the button is released before allowing another input.

### How would I improve the sorting hat?

**Model Improvements:**
- In this project, I did not adjust the decision tree model parameters after the initial training.  
- I focused mainly on data quantity: starting with 10 entries (0% accuracy), expanding to 50 entries (30% accuracy), and finally using 100 entries to achieve 100% accuracy.  
- This experience shows that having enough training data is critical to performance.

If I wanted to improve further, I would:
- Collect real user responses rather than synthetic data to better generalize.
- Fine-tune the decision tree parameters, such as maximum depth or minimum samples per split, to avoid overfitting.

**Hardware Improvements:**
- Add sound feedback (e.g., buzzer beep) when a button is pressed.
- Use capacitive touch sensors instead of mechanical buttons to improve user interaction smoothness.

**Model Suitability:**
- For the current 10-question format, the decision tree remains suitable because the number of features is small and easily interpretable.
- If additional sensors (like touch sliders or microphone input) were added, and the input became more continuous or noisy, I might consider using a Random Forest or a small Neural Network instead of a single decision tree.
  
# Key Observations
- Initially, I collected only 10 entries of data, and the model accuracy was very low (about 0%).
- After increasing to 50 entries, the model reached 30% accuracy.
- Finally, with 100 entries, the model achieved 100% accuracy during training and testing.
- This demonstrates the importance of having enough and varied training data to achieve better performance.
