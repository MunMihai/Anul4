import 'package:flutter/material.dart';

class GenderSelector extends StatelessWidget {
  final bool? isMale;
  final VoidCallback onMaleSelected;
  final VoidCallback onFemaleSelected;

  const GenderSelector({
    required this.isMale,
    required this.onMaleSelected,
    required this.onFemaleSelected,
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    bool isMaleSelected = isMale == true;
    bool isNotSelected = isMale == null;

    return Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Expanded(
          child: GestureDetector(
            onTap: onMaleSelected,
            child: Container(
              decoration: BoxDecoration(
                color: isNotSelected
                    ? Colors.white
                    : (isMaleSelected
                        ? const Color.fromARGB(255, 67, 115, 251)
                        : Colors.grey[200]),
                borderRadius: BorderRadius.circular(10),
              ),
              padding: const EdgeInsets.all(10),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Icon(
                    Icons.male,
                    size: 24,
                    color: isNotSelected
                        ? Colors.black
                        : (isMaleSelected
                            ? Colors.white
                            : const Color.fromARGB(255, 67, 115, 251)),
                  ),
                  const SizedBox(width: 10),
                  Text(
                    "Male",
                    style: TextStyle(
                      fontSize: 15,
                      fontWeight: FontWeight.bold,
                      color: isNotSelected
                          ? Colors.black
                          : (isMaleSelected
                              ? Colors.white
                              : const Color.fromARGB(255, 67, 115, 251)),
                    ),
                  ),
                ],
              ),
            ),
          ),
        ),
        const SizedBox(width: 20),
        Expanded(
          child: GestureDetector(
            onTap: onFemaleSelected,
            child: Container(
              decoration: BoxDecoration(
                color: isNotSelected
                    ? Colors.white
                    : (!isMaleSelected
                        ? const Color.fromARGB(255, 67, 115, 251)
                        : Colors.grey[200]),
                borderRadius: BorderRadius.circular(10),
              ),
              padding: const EdgeInsets.all(10),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Icon(
                    Icons.female,
                    size: 24,
                    color: isNotSelected
                        ? Colors.black
                        : (!isMaleSelected
                            ? Colors.white
                            : const Color.fromARGB(255, 67, 115, 251)),
                  ),
                  const SizedBox(width: 10),
                  Text(
                    "Female",
                    style: TextStyle(
                      fontSize: 15,
                      fontWeight: FontWeight.bold,
                      color: isNotSelected
                          ? Colors.black
                          : (!isMaleSelected
                              ? Colors.white
                              : const Color.fromARGB(255, 67, 115, 251)),
                    ),
                  ),
                ],
              ),
            ),
          ),
        ),
      ],
    );
  }
}
