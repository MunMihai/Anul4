import 'package:flutter/material.dart';
import 'package:loan_calculator/base/styles/app_styles.dart';

class AppButton extends StatelessWidget {
  const AppButton({super.key, required this.text, required this.onPressed});
  final String text;
  final VoidCallback onPressed;

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      width: double.infinity,
      child: ElevatedButton(
          onPressed: onPressed, 
          style: ElevatedButton.styleFrom(
          backgroundColor: const Color.fromARGB(255, 7, 55, 157), // Culoarea de fundal
          padding: const EdgeInsets.symmetric(vertical: 15, horizontal: 20), // Padding
          shape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(10), // Colțuri rotunjite
          ),
        ),
          child: Text(text, style: AppStyles.solidText)),
    );
  }
}
