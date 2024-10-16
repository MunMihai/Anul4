import 'package:doctor_app/base/common/styles/custom_icons.dart';
import 'package:flutter/material.dart';

import '../base/components/tab_items.dart';

List<CardTab> mookCardTabs = [
    CardTab(iconPath:TIcons.dentistry, title:'Dentistry', color: const Color.fromRGBO(220, 148, 151, 1)),
    CardTab(iconPath:TIcons.cardiology, title:'Cardiology', color: const Color.fromRGBO(147, 193, 158, 1)),
    CardTab(iconPath:TIcons.pulmonology, title:'Pulmonology', color: const Color.fromRGBO(245, 173, 126, 1)),
    CardTab(iconPath:TIcons.stethoscope, title:'General', color: const Color.fromRGBO(172, 161, 205, 1)),
    CardTab(iconPath:TIcons.brain, title:'Neurology', color: const Color.fromRGBO(77, 155, 145, 1)),
    CardTab(iconPath:TIcons.stomach, title:'Gastrointestinology', color: const Color.fromRGBO(53, 34, 97, 1)),
    CardTab(iconPath:TIcons.experiment, title:'Laboratory', color: const Color.fromRGBO(222, 182, 181, 1)),
    CardTab(iconPath:TIcons.syringe, title:'Vaccination', color: const Color.fromRGBO(137, 204, 219, 1)),
    CardTab(iconPath:TIcons.pharmacy, title:'Pharmacy'),
  ];