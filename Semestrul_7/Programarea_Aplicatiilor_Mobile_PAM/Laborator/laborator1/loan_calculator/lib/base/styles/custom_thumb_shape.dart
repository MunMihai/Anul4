import 'package:flutter/material.dart';

class CustomThumbShape extends SliderComponentShape {
  @override
  Size getPreferredSize(bool isEnabled, bool isDiscrete) {
    return const Size(24.0, 24.0);  // Dimensiunea thumb-ului
  }

  @override
  void paint(
    PaintingContext context,
    Offset center, {
    required Animation<double> activationAnimation,
    required Animation<double> enableAnimation,
    required bool isDiscrete,
    required TextPainter labelPainter,
    required RenderBox parentBox,
    required SliderThemeData sliderTheme,
    required TextDirection textDirection,
    required double value,
    required double textScaleFactor,
    required Size sizeWithOverflow,
  }) {
    final Canvas canvas = context.canvas;

    // Umbră
    Path thumbPath = Path()
      ..addOval(Rect.fromCircle(center: center, radius: 12.0));
    
    // Adaugă shadow
    canvas.drawShadow(thumbPath, Colors.black.withOpacity(0.5), 6.0, true);

    // Thumb-ul personalizat
    final Paint thumbPaint = Paint()
      ..color =  const Color.fromARGB(255, 18, 72, 189)// Culoarea de umplere
      ..style = PaintingStyle.fill;

    // Desenează cercul pentru thumb
    canvas.drawCircle(center, 10.0, thumbPaint);

    // Bordura thumb-ului
    final Paint borderPaint = Paint()
      ..color = Colors.white // Culoarea border-ului
      ..style = PaintingStyle.stroke
      ..strokeWidth = 5; // Grosimea border-ului

    // Desenează bordura în jurul thumb-ului
    canvas.drawCircle(center, 10.0, borderPaint);
  }
}
