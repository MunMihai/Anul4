import 'package:flutter/material.dart';

import '../styles/text_style.dart';

class CustomTab extends StatelessWidget {
  const CustomTab(
      {super.key,
      required this.iconPath,
      required this.title,
      required this.color});
  final String iconPath;
  final String title;
  final Color color;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Stack(children: [
          ClipRRect(
            borderRadius: BorderRadius.circular(8),
            child: Container(
              height: 62,
              color: color,
              padding: const EdgeInsets.all(10),
              child: Image.asset(
                iconPath,
                color: Colors.white,
              ),
            ),
          ),
          Positioned(
                top: -34.0,
                left: -34.0,
                child: CircleAvatar(
                  radius: 34.0,
                  backgroundColor: Colors.white.withOpacity(0.2),
                ),
              )
        ]),
        const SizedBox(
          height: 5,
        ),
        Text(
          //title.length > 10 ? '${title.substring(0, 8)}..' : title,
          title,
          overflow: TextOverflow.ellipsis,
          style: AppStyle.category,
        ),
      ],
    );
  }
}
