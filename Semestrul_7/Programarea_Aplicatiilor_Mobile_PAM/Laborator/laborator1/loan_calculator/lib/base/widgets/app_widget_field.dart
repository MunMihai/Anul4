import 'package:flutter/material.dart';
import 'package:loan_calculator/base/styles/app_styles.dart';

class AppWidgetField extends StatelessWidget {
  const AppWidgetField(
      {super.key,
      required this.mainText,
      required this.fieldText,
      required this.onChanged});
  final String mainText;
  final String fieldText;
  final ValueChanged<double> onChanged;

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(mainText, style: AppStyles.mainText),
        const SizedBox(height: 8),
        TextField(
          decoration: InputDecoration(
              fillColor: Colors.black26,
              labelText: fieldText,
              labelStyle: AppStyles.labelText,
              contentPadding: const EdgeInsets.symmetric(
                  vertical: 8, horizontal: 20), // Padding mai mic
              border: const OutlineInputBorder(
                  borderRadius: BorderRadius.all(Radius.circular(8)),
                  borderSide: BorderSide(color: Colors.grey))),
          keyboardType: TextInputType.number,
          onChanged: (value) {
            // Convertește la double și trimite valoarea
            if (value.isNotEmpty) {
              onChanged(double.parse(value)); // Trimite valoarea ca double
            } else {
              onChanged(0); // Trimite 0 dacă input-ul este gol
            }
          },
        ),
        const SizedBox(height: 40),
      ],
    );
  }
}
