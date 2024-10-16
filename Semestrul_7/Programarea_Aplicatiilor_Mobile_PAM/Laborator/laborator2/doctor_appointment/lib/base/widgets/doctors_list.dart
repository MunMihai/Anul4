import 'package:doctor_app/base/common/widgets/t_fillters.dart';
import 'package:flutter/material.dart';
import '../../mocks/mock_doctors.dart';
import '../common/styles/text_style.dart';
import '../common/widgets/doctor_visit_card.dart';
import '../components/doctor.dart';

class Cards extends StatefulWidget {
  const Cards({super.key});

  @override
  State<Cards> createState() => _CardsState();
}

class _CardsState extends State<Cards> {
  List<Doctor> sortedDoctors = List.from(mockDoctors);
  String selectedFilter = 'Default'; // Stochează tipul de filtrare selectat

  // Funcție pentru sortare
  void _sortDoctors(String criteria) {
    setState(() {
      if (criteria == 'name') {
        sortedDoctors.sort((a, b) => a.name.compareTo(b.name));
        selectedFilter = 'Name'; // Actualizează tipul de filtrare
      } else if (criteria == 'rating') {
        sortedDoctors.sort((a, b) => b.rating.compareTo(a.rating));
        selectedFilter = 'Rating'; // Actualizează tipul de filtrare
      } else if (criteria == 'reviews') {
        sortedDoctors.sort((a, b) => b.reviews.compareTo(a.reviews));
        selectedFilter = 'Reviews'; // Actualizează tipul de filtrare
      } else {
        sortedDoctors = List.from(mockDoctors);
        selectedFilter = 'Default';
      }
    });
  }

  // Toggle favorite pentru un doctor
  void _toggleFavorite(Doctor doctor) {
    setState(() {
      doctor.isFavorite = !doctor.isFavorite; // Schimbă starea favoritului
    });
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.symmetric(vertical: 10.0),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text(
                '${mockDoctors.length} founds',
                style: AppStyle.title,
              ),
              TFiltter(
                  selectedFilter: selectedFilter, onFilterChanged: _sortDoctors)
            ],
          ),
        ),
        Column(
          children: sortedDoctors.map((doctor) {
            return DoctorVisitCard(onFavoriteToggle: () => _toggleFavorite(doctor),
              doctorInfo: doctor,
            );
          }).toList(),
        ),
      ],
    );
  }
}
