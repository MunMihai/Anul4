import 'dart:math';
import 'package:flutter/material.dart';

class CardTab {
  final String iconPath;
  final String title;
  final Color color;

  CardTab({required this.iconPath, required this.title, Color? color}) : color = color ?? getRandomColor(); // Assign random color during initialization

  static Color getRandomColor() { // Make it static to call without an instance
    final Random random = Random();
    return Color.fromARGB(
      255, // Opacity (100%)
      random.nextInt(256), // Red value (0-255)
      random.nextInt(256), // Green value (0-255)
      random.nextInt(256), // Blue value (0-255)
    );
  }
}
