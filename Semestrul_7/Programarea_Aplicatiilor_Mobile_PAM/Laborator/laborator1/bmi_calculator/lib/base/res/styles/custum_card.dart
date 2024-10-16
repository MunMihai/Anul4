import 'package:flutter/material.dart';

class CustomCard extends StatelessWidget {
  final String label;
  final String value;
  final VoidCallback onMinusTap;
  final VoidCallback onPlusTap;

  const CustomCard({
    required this.label,
    required this.value,
    required this.onMinusTap,
    required this.onPlusTap,
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: 220,
      child: Card(
        elevation: 0,
        color: Colors.white,
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Text(
                label,
                style: const TextStyle(
                    fontSize: 15, color: Color.fromARGB(255, 140, 140, 140)),
              ),
              const SizedBox(height: 10),
              Text(
                value,
                style: const TextStyle(
                  fontSize: 64,
                  color: Colors.black,
                  fontWeight: FontWeight.bold,
                ),
              ),
              const SizedBox(height: 10),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Container(
                    decoration: BoxDecoration(
                      color: const Color.fromARGB(255, 67, 115, 251),
                      borderRadius: BorderRadius.circular(10),
                    ),
                    width: 42,
                    height: 42,
                    child: IconButton(
                      icon: const Icon(
                        Icons.remove,
                        color: Colors.white,
                      ),
                      onPressed: onMinusTap,
                      iconSize: 16,
                    ),
                  ),
                  const SizedBox(width: 10),
                  Container(
                    decoration: BoxDecoration(
                      color: const Color.fromARGB(255, 67, 115, 251),
                      borderRadius: BorderRadius.circular(10),
                    ),
                    width: 42,
                    height: 42,
                    child: IconButton(
                      icon: const Icon(
                        Icons.add,
                        color: Colors.white,
                      ),
                      onPressed: onPlusTap,
                      iconSize: 16,
                    ),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }
}
