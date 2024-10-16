import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

class AppStyles {
  static TextStyle mainText = GoogleFonts.ptSans(
      fontWeight: FontWeight.w700, fontSize: 14, color: const Color.fromARGB(255, 0, 0, 0));
  static TextStyle labelText = GoogleFonts.ptSans(
      fontWeight: FontWeight.w500, fontSize: 16, color: Colors.grey);
  static TextStyle solidText = GoogleFonts.ptSans(
      fontWeight: FontWeight.w500, fontSize: 18, color: const Color.fromARGB(255, 255, 255, 255));
  static TextStyle headerText = GoogleFonts.ptSans(
      fontWeight: FontWeight.w900, fontSize: 40, color: const Color.fromARGB(255, 0, 0, 0));
}
