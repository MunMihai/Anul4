class Doctor {
  final String name;
  final String location;
  final double rating;
  final String specialization;
  final String image;
  final int reviews;
  bool isFavorite;
  

  Doctor({
    required this.name,
    required this.location,
    required this.rating,
    required this.specialization,
    required this.image,
    required this.reviews,
    this.isFavorite = false, // Setare implicită
  });
}
