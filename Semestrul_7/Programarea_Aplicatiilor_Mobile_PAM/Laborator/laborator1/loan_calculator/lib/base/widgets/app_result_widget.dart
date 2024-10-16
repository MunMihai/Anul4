import 'package:flutter/material.dart';
import 'package:loan_calculator/base/styles/app_styles.dart';

class AppResultWidget extends StatefulWidget {
  const AppResultWidget({super.key, required this.monthlyAmount});
  final String monthlyAmount; 
  @override
  State<AppResultWidget> createState() => _AppResultWidgetState();
}

class _AppResultWidgetState extends State<AppResultWidget> {
  @override
  Widget build(BuildContext context) {
    return Card(
      color: const Color.fromARGB(255,241, 242, 246),
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.circular(20),
      ),
      elevation: 1,
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 50, vertical: 10),
              child: Text(
                'You will pay the approximate amount monthly:',
                style: AppStyles.headerText.copyWith(fontSize: 24),
                textAlign: TextAlign.center,
              ),
            ),
            Container(
              width: double.infinity,
              padding: const EdgeInsets.all(20),
              color: Colors.white,
              child: Text('${widget.monthlyAmount}\$',
                style: AppStyles.headerText.copyWith(
                    fontSize: 24, color: const Color.fromARGB(255, 7, 55, 157)),
                textAlign: TextAlign.center,
              ),
            ),
          ],
        ),
    );
  }
}
