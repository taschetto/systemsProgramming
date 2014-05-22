#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned char byte;

struct Pixel
{
  byte red, green, blue;
};

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    cout << "Usage: xxx file.ppm" << endl;
    return -1;
  }

  ifstream infile;
  infile.open(argv[1], ios::in);

  if (!infile.is_open())
  {
    cout << "Could't open file." << endl;
    return -1;
  }

  string type;
  int cols, rows, max;

  infile >> type >> cols >> rows >> max;

  Pixel** pixels = new Pixel*[cols];
  for (int i = 0; i < cols; i++)
    pixels[i] = new Pixel[rows];

  for (int i = 0; i < cols; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      int r, g, b;
      infile >> r >> g >> b;
      pixels[i][j].red = max - r;
      pixels[i][j].green = max - g;
      pixels[i][j].blue = max - b;
    }
  }

  if (infile.bad())
  {
	  cout << "File is bad." << endl;
		return -1;
	}

  infile.close();

  ofstream out;
  out.open("saida.ppm", ios::out);
  out << type << endl;
  out << cols << " " << rows << endl;
  out << max << endl;
  for (int i = 0; i < cols; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      out << (int)pixels[i][j].red << " " << (int)pixels[i][j].green << " " << (int)pixels[i][j].blue << " ";
    }
    out << endl;
  }
  out.close();

  for (int i = 0; i < cols; i++)
    delete[] pixels[i];
  delete[] pixels;

  return 0;
}
