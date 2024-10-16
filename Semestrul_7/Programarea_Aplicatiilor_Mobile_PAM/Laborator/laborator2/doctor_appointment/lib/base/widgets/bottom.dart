import 'package:doctor_app/base/widgets/medical_center_card.dart';
import 'package:flutter/material.dart';

import '../../mocks/mock_medical_centers.dart';
import '../common/widgets/t_section_heading.dart';

class Bottom extends StatelessWidget {
  const Bottom({super.key});


  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        TSectionHeading(title: 'Nearby Medical Centers', onPressed: (){},),
        SizedBox(
          height: 252,
          child: ListView.builder(
            scrollDirection: Axis.horizontal,
              itemCount: mockMedicalCenters.length,
              itemBuilder: (context, index) {
                final center = mockMedicalCenters[index];
                return Padding(
                padding: const EdgeInsets.only(right: 8.0),
                child: SizedBox(
                  width: 252, // Setează o lățime fixă pentru card
                  child: MedicalCenterCard(card: center),
                ),
              );
              }),
        )
      ],
    );
  }
}
