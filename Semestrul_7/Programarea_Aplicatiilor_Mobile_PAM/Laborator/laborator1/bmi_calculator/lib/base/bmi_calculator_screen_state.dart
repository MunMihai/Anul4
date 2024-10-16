import 'package:flutter/material.dart';
import 'res/styles/bmi_display.dart';
import 'res/styles/custum_card.dart';
import 'res/styles/gender_selector.dart';

class BMICalculatorScreen extends StatefulWidget {
  const BMICalculatorScreen({super.key});

  @override
  State<BMICalculatorScreen> createState() => _BMICalculatorScreenState();
}

class _BMICalculatorScreenState extends State<BMICalculatorScreen> {
  bool isMale = true;
  int weight = 70;
  int age = 23;
  double height = 170;
  double bmi = 0;
  String errorMessage = "";

  void calculateBMI() {
    setState(() {
      double heightInMeters = height / 100;
      bmi = weight / (heightInMeters * heightInMeters);
      errorMessage = "";
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color.fromARGB(255, 210, 216, 229),
      appBar: AppBar(
        centerTitle: true,
        toolbarHeight: 10,
      ),
      body: Padding(
        padding: const EdgeInsets.all(20.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Text(
              "Welcome 😊",
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.normal),
            ),
            const SizedBox(height: 10),
            const Text(
              "BMI Calculator",
              style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 20),
            GenderSelector(
              isMale: isMale,
              onMaleSelected: () => setState(() {
                isMale = true;
                errorMessage = "";
              }),
              onFemaleSelected: () => setState(() {
                isMale = false;
                errorMessage = "";
              }),
            ),
            if (errorMessage.isNotEmpty) ...[
              const SizedBox(height: 20),
              Text(
                errorMessage,
                style: const TextStyle(
                  color: Colors.red,
                  fontSize: 16,
                ),
              ),
            ],
            const SizedBox(height: 20),
            Expanded(
              child: Row(
                children: [
                  Expanded(
                    child: CustomCard(
                      label: "Weight",
                      value: "$weight",
                      onMinusTap: () => setState(
                          () => weight = weight > 0 ? weight - 1 : weight),
                      onPlusTap: () => setState(() => weight++),
                    ),
                  ),
                  const SizedBox(width: 20),
                  Expanded(
                    child: CustomCard(
                      label: "Age",
                      value: "$age",
                      onMinusTap: () =>
                          setState(() => age = age > 0 ? age - 1 : age),
                      onPlusTap: () => setState(() => age++),
                    ),
                  ),
                ],
              ),
            ),
            const SizedBox(height: 20),
            Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const Text(
                  "Height",
                  style: TextStyle(
                      fontSize: 14,
                      color: Colors.black,
                      fontWeight: FontWeight.bold),
                ),
                const SizedBox(height: 8),
                SizedBox(
                  width: 204,
                  height: 50,
                  child: TextField(
                    decoration: InputDecoration(
                      hintText: "Height",
                      hintStyle: const TextStyle(color: Colors.grey),
                      border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(10),
                        borderSide: BorderSide.none,
                      ),
                      fillColor: Colors.white,
                      filled: true,
                    ),
                    keyboardType: TextInputType.number,
                    onChanged: (value) => setState(
                        () => height = double.tryParse(value) ?? height),
                  ),
                ),
              ],
            ),
            const SizedBox(height: 20),
            BMIDisplay(bmi: bmi),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: calculateBMI,
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color.fromARGB(255, 67, 115, 251),
                foregroundColor: Colors.white,
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(10),
                ),
                minimumSize: const Size(double.infinity, 50),
              ),
              child: const Text(
                "Let's Go",
                style: TextStyle(fontSize: 15, fontWeight: FontWeight.w500),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
