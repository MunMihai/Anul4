import 'dart:convert';
//import 'dart:io';

import 'package:data/mocks/doctors_mock_data.dart';
import 'package:flutter/services.dart';
import '../models/doctor_model.dart';

abstract class DoctorLocalJsonDataSource {
  Future<List<DoctorModel>> getDoctors();
}

class DoctorLocalJsonDataSourceImpl implements DoctorLocalJsonDataSource {
  @override
  Future<List<DoctorModel>> getDoctors() async {
    try {
      //String json = await File('../presentation/assets/v1.json  ').readAsString();
      String json = await rootBundle.loadString('../presentation/assets/v1.json');
      var result = jsonDecode(json);

      return (result['doctors'] as List)
          .map((data) => DoctorModel.fromJson(data))
          .toList();
    } catch (e) {
      print('Error loading doctors: $e');
      await Future.delayed(Duration(seconds: 5));
      return doctorsMockData;
    }
  }
}
