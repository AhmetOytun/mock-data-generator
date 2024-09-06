#include <iostream>
#include <fstream>
#include <unordered_map>
#include <random>
#include <nlohmann/json.hpp>  // Include nlohmann/json.hpp library
#include <vector>
#include <string>

/* for simple syntax */
using ordered_json = nlohmann::ordered_json;

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

/* Get a random subset of the vector */
std::vector<std::string> getRandomSubset(const std::vector<std::string>& values, int minSize, int maxSize) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disSize(minSize, maxSize);
    std::uniform_int_distribution<> disIndex(0, values.size() - 1);

    std::vector<std::string> subset;
    int size = disSize(gen);

    for (int i = 0; i < size; ++i) {
        subset.push_back(values[disIndex(gen)]);
    }

    return subset;
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
    std::ifstream skin_problems_file("../values/skin_problems.txt");
    std::ifstream skin_type_file("../values/skin_types.txt");

    /* products used */
    std::ifstream cleansers_file("../values/cleansers.txt");
    std::ifstream exfoliants_file("../values/exfoliants.txt");
    std::ifstream moisturizers_file("../values/moisturizers.txt");
    std::ifstream sunscreens_file("../values/sunscreens.txt");
    std::ifstream toners_file("../values/toners.txt");
    std::ifstream serums_file("../values/serums.txt");
    std::ifstream eye_creams_file("../values/eye_creams.txt");
    std::ifstream masks_file("../values/masks.txt");
    std::ifstream spot_treatments_file("../values/spot_treatments.txt");
    std::ifstream face_oils_file("../values/face_oils.txt");
    std::ifstream face_mists_file("../values/face_mists.txt");
    std::ifstream face_scrubs_file("../values/face_scrubs.txt");
    std::ifstream retinols_file("../values/retinols.txt");
    std::ifstream lip_care_file("../values/lip_care.txt");
    std::ifstream essences_file("../values/essences.txt");



    /* error check */
    if (!ages_file || !genders_file || !locations_file || !alcohol_consumption_file || !allergy_causing_ingredients_file || !allergy_causing_products_file || !baumann_classification_file || !cigarette_consumption_file || !gluten_file || !hydration_file || !skin_problems_file || !skin_type_file || !cleansers_file || !exfoliants_file || !moisturizers_file || !sunscreens_file || !toners_file || !serums_file || !eye_creams_file || !masks_file || !spot_treatments_file || !face_oils_file || !face_mists_file || !face_scrubs_file || !retinols_file || !lip_care_file || !essences_file) {
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
    std::vector<std::string> skin_problems = setVectorsFromFile(skin_problems_file);
    std::vector<std::string> skin_type = setVectorsFromFile(skin_type_file);
    std::vector<std::string> cleansers = setVectorsFromFile(cleansers_file);
    std::vector<std::string> exfoliants = setVectorsFromFile(exfoliants_file);
    std::vector<std::string> moisturizers = setVectorsFromFile(moisturizers_file);
    std::vector<std::string> sunscreens = setVectorsFromFile(sunscreens_file);
    std::vector<std::string> toners = setVectorsFromFile(toners_file);
    std::vector<std::string> serums = setVectorsFromFile(serums_file);
    std::vector<std::string> eye_creams = setVectorsFromFile(eye_creams_file);
    std::vector<std::string> masks = setVectorsFromFile(masks_file);
    std::vector<std::string> spot_treatments = setVectorsFromFile(spot_treatments_file);
    std::vector<std::string> face_oils = setVectorsFromFile(face_oils_file);
    std::vector<std::string> face_mists = setVectorsFromFile(face_mists_file);
    std::vector<std::string> face_scrubs = setVectorsFromFile(face_scrubs_file);
    std::vector<std::string> retinols = setVectorsFromFile(retinols_file);
    std::vector<std::string> lip_care = setVectorsFromFile(lip_care_file);
    std::vector<std::string> essences = setVectorsFromFile(essences_file);



    for (int i = 0; i < 10000; ++i) {
        /* create a json record */
        ordered_json record;

        /* single values */
        record["Age"] = getRandomValueFromVector(ages);
        record["Gender"] = getRandomValueFromVector(genders);
        record["Location"] = getRandomValueFromVector(locations);
        record["Skin Type"] = getRandomValueFromVector(skin_type);

        /* multiple values with no complexity */
        record["Skin Problems"] = getRandomSubset(skin_problems, 1, 3);

        /* multiple values with complexity */
        record["Products Used"] = {
            {"Cleansers", getRandomSubset(cleansers, 1, 2)},
            {"Exfoliants", getRandomSubset(exfoliants, 0, 2)},
            {"Moisturizers", getRandomSubset(moisturizers ,1 , 3)},
            {"Sunscreens", getRandomSubset(sunscreens,0 , 2)},
            {"Toners", getRandomSubset(toners, 0, 1)},
            {"Serums", getRandomSubset(serums, 1, 3)},
            {"Eye Creams", getRandomSubset(eye_creams, 0, 1)},
            {"Masks", getRandomSubset(masks, 0, 2)},
            {"Spot Treatments", getRandomSubset(spot_treatments, 0, 2)},
            {"Face Oils", getRandomSubset(face_oils, 0, 1)},
            {"Face Mists", getRandomSubset(face_mists, 0, 1)},
            {"Face Scrubs", getRandomSubset(face_scrubs, 0, 1)},
            {"Retinols", getRandomSubset(retinols, 0, 1)},
            {"Lip Care", getRandomSubset(lip_care, 0, 2)},
            {"Essences", getRandomSubset(essences, 0, 1)}
        };

        /* multiple values with no complexity */
        record["Allergy Causing Products"] = getRandomSubset(allergy_causing_products, 0, 3);
        record["Allergy Causing Ingredients"] = getRandomSubset(allergy_causing_ingredients, 0, 4);

        /* single values */
        record["Cigarette Consumption"] = getRandomValueFromVector(cigarette_consumption);
        record["Alcohol Consumption"] = getRandomValueFromVector(alcohol_consumption);
        record["Hydration"] = getRandomValueFromVector(hydration);
        record["Gluten Food Habits"] = getRandomValueFromVector(gluten);
        record["Baumann Skin Profile"] = getRandomValueFromVector(baumann_classification);

        outFile << record.dump() << std::endl;
    }

    /* closing files */
    outFile.close();
    ages_file.close();
    alcohol_consumption_file.close();
    allergy_causing_ingredients_file.close();
    allergy_causing_products_file.close();
    baumann_classification_file.close();
    cigarette_consumption_file.close();
    gluten_file.close();
    hydration_file.close();
    locations_file.close();
    skin_problems_file.close();
    skin_type_file.close();
    cleansers_file.close();
    exfoliants_file.close();
    moisturizers_file.close();
    sunscreens_file.close();
    toners_file.close();
    serums_file.close();
    eye_creams_file.close();
    masks_file.close();
    spot_treatments_file.close();
    face_oils_file.close();
    face_mists_file.close();
    face_scrubs_file.close();
    retinols_file.close();
    lip_care_file.close();
    essences_file.close();

    std::cout << "Data successfully written to data.jsonl" << std::endl;
    return 0;
}
