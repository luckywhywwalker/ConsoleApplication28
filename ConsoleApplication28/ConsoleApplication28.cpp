#include <iostream>
using namespace std;
struct Rectangle {
    char name[50];
    int height;
    int width;
};
void printRectangle(const Rectangle& rectangle) {
    for (int i = 0; i < rectangle.height; i++) {
        for (int j = 0; j < rectangle.width; j++) {
            if (i == 0 || i == rectangle.height - 1 || j == 0 || j == rectangle.width - 1)
                cout << "@";
            else
                cout << " ";
        }
        cout << endl;
    }
}
void fillRectangle(Rectangle& rectangle) {
    cout << "Enter name: ";
    cin >> rectangle.name;
    cout << "Enter height: ";
    cin >> rectangle.height;
    cout << "Enter width: ";
    cin >> rectangle.width;
}
void editRectangle(Rectangle& rectangle) {
    cout << "Editing Rectangle: " << rectangle.name << endl;
    fillRectangle(rectangle);
}
int main() {
    int countRectangles;
    cout << "Enter the number of rectangles: ";
    cin >> countRectangles;
    Rectangle* rectangles = new Rectangle[countRectangles];
    for (int i = 0; i < countRectangles; i++) {
        cout << "Rectangle #" << i + 1 << endl;
        fillRectangle(rectangles[i]);
    }
    for (int i = 0; i < countRectangles; i++) {
        cout << "Rectangle #" << i + 1 << ": " << rectangles[i].name << endl;
        printRectangle(rectangles[i]);
    }
    int editIndex;
    cout << "Enter the rectangle number to edit (1 to " << countRectangles << ", or 0 to cancel): ";
    cin >> editIndex;
    if (editIndex >= 1 && editIndex <= countRectangles) {
        editRectangle(rectangles[editIndex - 1]);
    }
    else {
        cout << "Edit canceled." << endl;
    }
    cout << "Updated list of rectangles:" << endl;
    for (int i = 0; i < countRectangles; i++) {
        cout << "Rectangle #" << i + 1 << ": " << rectangles[i].name << endl;
        printRectangle(rectangles[i]);
    }
    delete[] rectangles;
    return 0;
}
