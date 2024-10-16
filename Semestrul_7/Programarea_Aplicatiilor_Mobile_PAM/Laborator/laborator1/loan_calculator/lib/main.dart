import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:loan_calculator/base/styles/app_styles.dart';
import 'package:loan_calculator/base/widgets/app_result_widget.dart';
import 'package:loan_calculator/base/widgets/app_solid_button.dart';
import 'package:loan_calculator/base/widgets/app_widget_field.dart';
import 'dart:math';

import 'base/styles/custom_thumb_shape.dart';

void main() {
  runApp(const LoanCalculatorApp());
}

class LoanCalculatorApp extends StatelessWidget {
  const LoanCalculatorApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      debugShowCheckedModeBanner: false,
      home: LoanCalculatorScreen(),
    );
  }
}

class LoanCalculatorScreen extends StatefulWidget {
  const LoanCalculatorScreen({super.key});

  @override
  State<LoanCalculatorScreen> createState() => _LoanCalculatorScreenState();
}

class _LoanCalculatorScreenState extends State<LoanCalculatorScreen> {
  double _amount = 0.0;
  double _monthlyRate = 0.0;
  int _numberOfMonths = 0;
  String _monthlyAmount = '3.943';

  void _onButtonPressed() {
    double r = _monthlyRate / 100;
    double numerator = _amount * r * pow((1 + r), _numberOfMonths);
    double denomirator = pow((1 + r), _numberOfMonths) - 1;
    setState(() {
      _monthlyAmount = (numerator / denomirator).toStringAsFixed(3);
    });
  }

  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: AnnotatedRegion(
      value: const SystemUiOverlayStyle(
        statusBarColor: Colors.white,
        statusBarIconBrightness: Brightness.dark,
      ),
      child: Scaffold(
        backgroundColor: Colors.white,
        // appBar: AppBar(
        //   backgroundColor: Colors.blue,
        // ),
        body: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 36, vertical: 20),
          child: Column(
            children: [
              Text(
                "Loan Calculator",
                style: AppStyles.headerText.copyWith(letterSpacing: 3),
                textAlign: TextAlign.center,
              ),
              Padding(
                padding: const EdgeInsets.symmetric(vertical: 40),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    AppWidgetField(
                      mainText: "Enter Amount",
                      fieldText: "Amount",
                      onChanged: (value) {
                        setState(() {
                          _amount = value;
                        });
                      },
                    ),
                    Text("Enter number of months", style: AppStyles.mainText),
                    SliderTheme(
                      data: SliderTheme.of(context).copyWith(
                        thumbShape: CustomThumbShape(),
                        trackHeight: 8
                      ),
                      child: Slider(
                        value: _numberOfMonths.toDouble(),
                        min: 0,
                        max: 60,
                        divisions: 60,
                        label: _numberOfMonths.toString(),
                        activeColor: const Color.fromARGB(255, 36, 105, 254),
                        onChanged: (double value) {
                          setState(() {
                            _numberOfMonths = value.round();
                          });
                        },
                      ),
                    ),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: [
                        Text("1",
                            style: AppStyles.labelText.copyWith(
                                fontWeight: FontWeight.w400, fontSize: 12)),
                        Text("60 luni",
                            style: AppStyles.labelText.copyWith(
                                fontWeight: FontWeight.w400, fontSize: 12)),
                      ],
                    ),
                    const SizedBox(height: 20),
                    AppWidgetField(
                      mainText: "Enter % per months",
                      fieldText: "Percent",
                      onChanged: (value) {
                        setState(() {
                          _monthlyRate = value;
                        });
                      },
                    ),
                    const SizedBox(height: 10),
                    AppResultWidget(
                      monthlyAmount: _monthlyAmount,
                    ),
                    const SizedBox(height: 20),
                    AppButton(
                      text: "Calculate",
                      onPressed: _onButtonPressed,
                    )
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    ));
  }
}

