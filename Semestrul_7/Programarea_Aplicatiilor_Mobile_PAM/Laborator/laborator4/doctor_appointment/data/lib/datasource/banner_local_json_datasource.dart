import 'dart:convert';
//import 'dart:io';

import 'package:data/mocks/banner_mock_data.dart';
import 'package:flutter/services.dart';

import '../models/banner_model.dart'; // Pentru manipularea JSON

abstract class BannerLocalJsonDataSource {
  Future<List<BannerModel>> getBanners();
}

class BannerLocalJsonDataSourceImpl implements BannerLocalJsonDataSource {
  @override
  Future<List<BannerModel>> getBanners() async {
    try {
      //String json = await File('D:/Universitate/Semestrul_7/Programarea_Aplicatiilor_Mobile_PAM/Laborator/laborator4/doctor_appointment/presentation/assets/localData.json').readAsString();
      String json = await rootBundle.loadString('../presentation/assets/v1.json');
      var result = jsonDecode(json);
      print('JSON Data: $json');

      return (result['banners'] as List)
          .map((data) => BannerModel.fromJson(data))
          .toList();
    } catch (e) {
      print('Error loading banners: $e');
      await Future.delayed(Duration(seconds: 5));
      return bannersMockData;
    }
  }
}
