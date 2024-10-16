import 'dart:math';

import 'package:doctor_app/base/common/styles/text_style.dart';
import 'package:doctor_app/base/common/widgets/t_divider.dart';
import 'package:doctor_app/base/common/widgets/t_icon_text.dart';
import 'package:flutter/material.dart';
import 'package:flutter_rating/flutter_rating.dart';
import '../common/styles/custom_icons.dart';
import '../components/medical_center.dart'; // Asigură-te că acest import este corect

class MedicalCenterCard extends StatelessWidget {
  const MedicalCenterCard({super.key, required this.card});
  final MedicalCenter card;

  // final String locationIcon = 'assets/icon/location.png';
  // final String destinationIcon = 'assets/icon/destination.png';
  // final String hospitalIcon = 'assets/icon/hospital.png';

  @override
  Widget build(BuildContext context) {
    return Card(
      color: Colors.white,
      elevation: 2, // Adaugă o umbră
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          ClipRRect(
            borderRadius: const BorderRadius.vertical(
                top: Radius.circular(10.0)), // Rounding corners
            child: Image.asset(
              card.imagePath, // Calea imaginii
              fit: BoxFit.cover, // Fitting image
              height: 121, // Înălțimea imaginii
              width: double.infinity, // Lățimea completă
            ),
          ),
          Padding(
            padding:
                const EdgeInsets.only(top: 8, left: 12, right: 12, bottom: 12),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(
                  card.name, // Numele centrului
                  style: AppStyle.title.copyWith(fontSize: 14), // Font îngroșat
                ),
                const SizedBox(height: 4), // Spațiu între elemente

                TIconText(
                    text: card.location,
                    iconPath: TIcons.location,
                    iconSize: 14),
                const SizedBox(height: 4), // Spațiu între elemente
                Row(
                  children: [
                    Text(
                      card.rating.toString(), // Afișează ratingul
                      style: AppStyle.seeAll.copyWith(
                          fontWeight: FontWeight.w600,
                          fontSize: 12), // Stil pentru text
                    ),
                    const SizedBox(width: 4),
                    StarRating(
                      rating: card.rating,
                      color: const Color.fromRGBO(254, 176, 82, 1),
                      size: 16,
                    ),
                    const SizedBox(width: 4),
                    Text('(${Random().nextInt(1000) + 1} Reviews)',
                        style: AppStyle.seeAll.copyWith(
                            fontWeight: FontWeight.w400, fontSize: 12))
                  ],
                ),
                const TDivider(),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    TIconText(
                        text: '2.5km/40min', iconPath: TIcons.destination),
                    TIconText(text: 'Hospital', iconPath: TIcons.hospital),
                  ],
                )
              ],
            ),
          ),
        ],
      ),
    );
  }
}
