#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {
private:
	double x, y;

public:
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	double getX() const { return x; }
	double getY() const { return y; }
};

class Color {
private:
	int r, g, b;

public:
	Color(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}
	int getR() const { return r; }
	int getG() const { return g; }
	int getB() const { return b; }
};

class Painter {
private:
	string tool;

public:
	Painter(const string& tool = "Brush") : tool(tool) {}
	string getTool() const { return tool; }
	void setTool(const string& tool) { this->tool = tool; }
};

class Shape {
protected:
	Point position;
	Color color;
	Painter painter;

public:
	Shape(const Point& position, const Color& color, const Painter& painter)
		: position(position), color(color), painter(painter) {}
	Point getPosition() const { return position; }
	Color getColor() const { return color; }
	Painter getPainter() const { return painter; }
	virtual void print() const {
		cout << "Shape at (" << position.getX() << ", " << position.getY() << ") "
			 << "Color(RGB): (" << color.getR() << ", " << color.getG() << ", " << color.getB() << ") "
			 << "Painter Tool: " << painter.getTool() << endl;
	}
	virtual ~Shape() {}
};

class Line : public Shape {
private:
	Point endPoint;

public:
	Line(const Point& start, const Point& end, const Color& color, const Painter& painter)
		: Shape(start, color, painter), endPoint(end) {}
	Point getEndPoint() const { return endPoint; }
	void print() const override {
		cout << "Line: " << endl;
		cout << "From (" << position.getX() << ", " << position.getY() << ") "
			 << "to (" << endPoint.getX() << ", " << endPoint.getY() << ") " << endl
			 << "Color(RGB): (" << color.getR() << ", " << color.getG() << ", " << color.getB() << ") "
			 << endl
			 << "Painter Tool: " << painter.getTool() << endl;
	}
};

class Circle : public Shape {
private:
	double radius;

public:
	Circle(const Point& center, double radius, const Color& color, const Painter& painter)
		: Shape(center, color, painter), radius(radius) {}
	double getRadius() const { return radius; }
	void setRadius(double radius) { this->radius = radius; }
	void print() const override {
		cout << "Circle: " << endl;
		cout << "Center: (" << position.getX() << ", " << position.getY() << ") " << endl
			 << "Radius: " << radius << " " << endl
			 << "Color(RGB): (" << color.getR() << ", " << color.getG() << ", " << color.getB() << ") "
			 << endl
			 << "Painter Tool: " << painter.getTool() << endl;
	}
};

class Rectangle : public Shape {
private:
	double width, height;

public:
	Rectangle(const Point& topLeft, double width, double height, const Color& color, const Painter& painter)
		: Shape(topLeft, color, painter), width(width), height(height) {}
	double getWidth() const { return width; }
	double getHeight() const { return height; }
	void setWidth(double width) { this->width = width; }
	void setHeight(double height) { this->height = height; }
	bool equals(const Rectangle& other) const {
		return (getPosition().getX() == other.getPosition().getX() &&
				getPosition().getY() == other.getPosition().getY() && width == other.width &&
				height == other.height && getColor().getR() == other.getColor().getR() &&
				getColor().getG() == other.getColor().getG() &&
				getColor().getB() == other.getColor().getB() &&
				getPainter().getTool() == other.getPainter().getTool());
	}
	void print() const override {
		cout << "Rectangle: " << endl;
		cout << "Top-left: (" << position.getX() << ", " << position.getY() << ") " << endl
			 << "Width: " << width << ", Height: " << height << " " << endl
			 << "Color(RGB): (" << color.getR() << ", " << color.getG() << ", " << color.getB() << ") "
			 << endl
			 << "Painter Tool: " << painter.getTool() << endl;
	}
};

class Image : public Shape {
private:
	vector<Shape*> shapes;

public:
	Image(const Point& position, const Color& color, const Painter& painter)
		: Shape(position, color, painter) {}

	void addShape(Shape* shape) { shapes.push_back(shape); }

	void print() const {
		cout << "------------- IMAGE -------------" << endl;
		if (shapes.empty()) {
			cout << "Buc tranh trong rong!" << endl;
			return;
		}

		for (const auto& s : shapes) {
			s->print();
			cout << endl;
		}
		cout << "---------------------------------" << endl;
	}

	~Image() {
		for (auto& s : shapes) {
			delete s;
		}
		shapes.clear();
	}
};

int main() {
	Image img(Point(0, 0), Color(255, 255, 255), Painter("Eraser"));

	Line* line = new Line(Point(0, 0), Point(10, 10), Color(255, 0, 0), Painter("Pencil"));
	Circle* circle = new Circle(Point(5, 5), 3.0, Color(0, 255, 0), Painter("Brush"));
	Rectangle* rectangle = new Rectangle(Point(2, 2), 4.0, 6.0, Color(0, 0, 255), Painter("Marker"));

	img.addShape(line);
	img.addShape(circle);
	img.addShape(rectangle);

	img.print();

	return 0;
}