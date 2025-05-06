Overview

This project implements a “Sorting Hat” prototype that classifies users into Hogwarts houses based on their responses to a series of questions.
The system runs on an ESP32 and uses a small machine learning model trained on synthetic survey data.

Project Components
	•	ESP32 Dev Board
	•	4 Push Buttons for answering questions
	•	OLED Display to show questions and results

My Work
	•	Generated a synthetic dataset to simulate user quiz responses.
	•	Trained a Decision Tree Classifier using the generated data.
	•	Exported the trained model into C++ format (sorting_hat_model.h) for deployment on ESP32.
	•	Programmed the ESP32 to:
	•	Display questions and options on an OLED screen.
	•	Collect user answers through button inputs.
	•	Predict and display the assigned Hogwarts house.

Key Observations
	•	Initially, I collected only 10 entries of data, and the model accuracy was very low (about 0%).
	•	After increasing to 50 entries, the model reached 30% accuracy.
	•	Finally, with 100 entries, the model achieved 100% accuracy during training and testing.
	•	This demonstrates the importance of having enough and varied training data to achieve better performance.
