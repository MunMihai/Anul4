import 'package:flutter/material.dart';

import '../../mocks/mock_card_tabs.dart';
import '../common/widgets/t_section_heading.dart';
import '../common/widgets/tab.dart';

class Middle extends StatefulWidget {
  const Middle({super.key});

  @override
  State<Middle> createState() => _MiddleState();
}

class _MiddleState extends State<Middle> {
  // State variable to track if the option has been pressed
  bool isCollapsed = true;

  void _toggleCollapse() {
    setState(() {
      isCollapsed = !isCollapsed; // Toggle the collapse state
    });
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        TSectionHeading(
          title: 'Categories',
          onPressed: _toggleCollapse,
        ),
        GridView.builder(
          gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
            crossAxisCount: 4, // Number of columns
            childAspectRatio: 1, // Adjust the aspect ratio for layout
            crossAxisSpacing: 20,
            mainAxisSpacing: 10,
          ),
          itemCount: isCollapsed
              ? (mookCardTabs.length < 8 ? mookCardTabs.length : 8)
              : mookCardTabs.length, // Display based on the option pressed
          shrinkWrap: true, // Shrink the grid to fit the content
          physics: const NeverScrollableScrollPhysics(), // Disable scrolling
          itemBuilder: (context, index) {
            return CustomTab(
              iconPath: mookCardTabs[index].iconPath,
              title: mookCardTabs[index].title,
              color: mookCardTabs[index].color,
            );
          },
        ),
      ],
    );
  }
}
