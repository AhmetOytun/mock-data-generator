#include <iostream>
#include <fstream>
#include <unordered_map>
#include <random>
#include <nlohmann/json.hpp>  // Include nlohmann/json.hpp library
#include <vector>
#include <string>

/* for simple syntax */
using json = nlohmann::json;
/* set vectors from the file by reading the file line by line */
std::vector<std::string> setVectorsFromFile(std::ifstream& file) {
    std::vector<std::string> values;
    std::string line;
    while (std::getline(file, line)) {
        values.push_back(line);
    }
    return values;
}

/* get random value from the vector */
template <typename T>
T getRandomValueFromVector(std::vector<T>& values) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, values.size() - 1);
    return values[dis(gen)];
}

int main() {
    /* open a jsonl file to write the data */
    std::ofstream outFile("mockdata.jsonl");

    /* error check */
    if (!outFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    /* txt files that contains the values */
    std::ifstream ages_file("../values/ages.txt");
    std::ifstream genders_file("../values/genders.txt");
    std::ifstream locations_file("../values/locations.txt");
    std::ifstream alcohol_consumption_file("../values/alcohol_consumption.txt");
    std::ifstream allergy_causing_ingredients_file("../values/allergy_causing_ingredients.txt");
    std::ifstream allergy_causing_products_file("../values/allergy_causing_products.txt");
    std::ifstream baumann_classification_file("../values/baumann.txt");
    std::ifstream cigarette_consumption_file("../values/cigarette_consumption.txt");
    std::ifstream gluten_file("../values/gluten.txt");
    std::ifstream hydration_file("../values/hydration.txt");
    std::ifstream products_used_file("../values/products_used.txt");
    std::ifstream skin_problems_file("../values/skin_problems.txt");
    std::ifstream skin_type_file("../values/skin_types.txt");

    /* error check */
    if (!ages_file || !genders_file || !locations_file || !alcohol_consumption_file || !allergy_causing_ingredients_file || !allergy_causing_products_file || !baumann_classification_file || !cigarette_consumption_file || !gluten_file || !hydration_file || !products_used_file || !skin_problems_file || !skin_type_file) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    /* vectors to hold data */
    std::vector<std::string> ages = setVectorsFromFile(ages_file);
    std::vector<std::string> genders = setVectorsFromFile(genders_file);
    std::vector<std::string> locations = setVectorsFromFile(locations_file);
    std::vector<std::string> alcohol_consumption = setVectorsFromFile(alcohol_consumption_file);
    std::vector<std::string> allergy_causing_ingredients = setVectorsFromFile(allergy_causing_ingredients_file);
    std::vector<std::string> allergy_causing_products = setVectorsFromFile(allergy_causing_products_file);
    std::vector<std::string> baumann_classification = setVectorsFromFile(baumann_classification_file);
    std::vector<std::string> cigarette_consumption = setVectorsFromFile(cigarette_consumption_file);
    std::vector<std::string> gluten = setVectorsFromFile(gluten_file);
    std::vector<std::string> hydration = setVectorsFromFile(hydration_file);
    std::vector<std::string> products_used = setVectorsFromFile(products_used_file);
    std::vector<std::string> skin_problems = setVectorsFromFile(skin_problems_file);
    std::vector<std::string> skin_type = setVectorsFromFile(skin_type_file);


    // Generate random data for 10 records
    for (int i = 0; i < 10000; ++i) {
        std::unordered_map<std::string, json> record;

        record["Age"] = getRandomValueFromVector(ages);
        record["Gender"] = getRandomValueFromVector(genders);
        record["Location"] = getRandomValueFromVector(locations);
        record["Skin Type"] = getRandomValueFromVector(skin_type);
        record["Skin Problems"] = getRandomValueFromVector(skin_problems);
        record["Products Used"] = getRandomValueFromVector(products_used);
        record["Allergy Causing Products"] = getRandomValueFromVector(allergy_causing_products);
        record["Allergy Causing Ingredients"] = getRandomValueFromVector(allergy_causing_ingredients);
        record["Cigarette Consumption"] = getRandomValueFromVector(cigarette_consumption);
        record["Alcohol Consumption"] = getRandomValueFromVector(alcohol_consumption);
        record["Hydration"] = getRandomValueFromVector(hydration);
        record["Gluten Food Habits"] = getRandomValueFromVector(gluten);
        record["Baumann Skin Profile"] = getRandomValueFromVector(baumann_classification);

        // Convert map to JSON object
        json jsonObject(record);
        
        // Write JSON object to file in JSONL format
        outFile << jsonObject.dump() << "\n";
    }

    outFile.close();
    std::cout << "Data successfully written to data.jsonl" << std::endl;
    return 0;
}
