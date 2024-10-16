import 'package:bmi_calculator/base/res/styles/bmi_utilities.dart';
import 'package:flutter/material.dart';

class BMIDisplay extends StatelessWidget {
  final double bmi;

  const BMIDisplay({required this.bmi, super.key});

  @override
  Widget build(BuildContext context) {
    String bmiText = bmi == 0 ? "" : bmi.toStringAsFixed(1);
    String status = bmi == 0 ? "" : getBMIStatus(bmi);

    return Center(
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          Text(
            bmiText,
            style: const TextStyle(
              fontSize: 67,
              fontWeight: FontWeight.bold,
              color: Color.fromARGB(255, 67, 115, 251),
            ),
          ),
          if (status.isNotEmpty) ...[
            Text(
              status,
              style: const TextStyle(
                fontSize: 30,
                fontWeight: FontWeight.w600,
                color: Color.fromARGB(255, 67, 115, 251),
              ),
            ),
          ],
        ],
      ),
    );
  }
}
