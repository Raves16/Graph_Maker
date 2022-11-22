#include "pbPlot.hpp"
#include "SupportLib.hpp"
#include "Functions.hpp"
#include <direct.h>
#include <cmath>

int draw_quadratic_function(std::string function)
{
	_mkdir("./Quadratic");
	bool success;
	double D = (pow(get_b_quadratic(function), 2)) - (4 * get_a_quadratic(function) * get_c_quadratic(function));
	StringReference* errorMessage = CreateStringReferenceLengthValue(0, L' ');
	RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

	double xsa[17];

	double* aryPtr = funcArray(D, 17, function);

	for (int i = 0; i < 17; i++)
	{
		xsa[i] = aryPtr[i];
	}
	

	std::vector<double> xs(xsa, xsa + sizeof(xsa) / sizeof(double));

	double ysa[17];

	for (int i = 0; i < 17; i++)
	{
		ysa[i] = calculate_function(function, xsa[i]);
	}


	std::vector<double> ys(ysa, ysa + sizeof(ysa) / sizeof(double));

	ScatterPlotSeries* series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &xs;
	series->ys = &ys;
	series->linearInterpolation = true;
	series->lineType = toVector(L"dashed");
	series->lineThickness = 2;
	series->color = GetGray(0.3);

	ScatterPlotSettings* settings = GetDefaultScatterPlotSettings();
	settings->width = 1000;
	settings->height = 800;
	settings->autoBoundaries = true;
	settings->autoPadding = false;
	settings->yPadding = 50;
	settings->xPadding = 50;
	settings->title = toVector(L"Graph");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);

	success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);
	if (success) {
		double x1 = MapXCoordinateBasedOnSettings(get_x(function), settings);
		double y1 = MapYCoordinateBasedOnSettings(calculate_function(function, get_x(function)), settings);

		if (get_a_quadratic(function) > 0)
		{
			DrawText(imageReference->image, x1 + 15, y1 - 50, toVector(L"Minimum"), GetGray(0.5));
		}
		else if (get_a_quadratic(function) < 0)
		{
			DrawText(imageReference->image, x1 + 15, y1 + 40, toVector(L"Maximum"), GetGray(0.5));
		}
		DrawFilledCircle(imageReference->image, x1, y1, 5, GetGray(0.5));

		if (D > 0)
		{
			double x2 = MapXCoordinateBasedOnSettings(get_x_zero_positive(function), settings);
			double y2 = MapYCoordinateBasedOnSettings(calculate_function(function, get_x_zero_positive(function)), settings);
			double x3 = MapXCoordinateBasedOnSettings(get_x_zero_negative(function), settings);
			double y3 = MapYCoordinateBasedOnSettings(calculate_function(function, get_x_zero_negative(function)), settings);

			DrawText(imageReference->image, x2 + 15, y2 - 30, toVector(L"x1"), GetGray(0.5));
			DrawText(imageReference->image, x3 + 15, y3 - 30, toVector(L"x2"), GetGray(0.5));

			DrawFilledCircle(imageReference->image, x2, y2, 5, GetGray(0.5));
			DrawFilledCircle(imageReference->image, x3, y3, 5, GetGray(0.5));
		}
		else if (D == 0)
		{
			double x2 = MapXCoordinateBasedOnSettings(get_x_zero_positive(function), settings);
			double y2 = MapYCoordinateBasedOnSettings(calculate_function(function, get_x_zero_positive(function)), settings);
			DrawText(imageReference->image, x2 + 15, y2 - 30, toVector(L"x1"), GetGray(0.5));
			DrawFilledCircle(imageReference->image, x2, y2, 5, GetGray(0.5));
		}

		std::vector<double>* pngdata = ConvertToPNG(imageReference->image);
		WriteToFile(pngdata, "Quadratic/quadratic.png");
		DeleteImage(imageReference->image);
	}
	else {
		std::cerr << "Error: ";
		for (int i = 0; i < errorMessage->string->size(); i++) {
			std::wcerr << errorMessage->string->at(i);
		}
		std::cerr << std::endl;
	}

	FreeAllocations();

	return success ? 0 : 1;
}

int draw_hyperbola_function(std::string function)
{
	_mkdir("./Hyperbola");
	bool success;
	StringReference* errorMessage = CreateStringReferenceLengthValue(0, L' ');
	RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();
	RGBABitmapImageReference* canvasReference2 = CreateRGBABitmapImageReference();
	RGBABitmapImage* combined = CreateImage(1000 * 2, 400 * 2, GetWhite());
	RGBABitmapImage* image1, *image2;

	double xsa[20];

	for (int i = 0; i < 20; i++)
	{
		xsa[i] = i + 1;
	}
	std::vector<double> xs(xsa, xsa + sizeof(xsa) / sizeof(double));

	double ysa[20];

	for (int j = 0; j < 19; j++)
	{
		ysa[j] = calculate_hyperbola_function(function, xsa[j]);
	}
	ysa[19] = calculate_hyperbola_function(function, xsa[19]);
	std::vector<double> ys(ysa, ysa + sizeof(ysa) / sizeof(double));


	double xsa2[20];

	for (int i = 0; i < 20; i++)
	{
		xsa2[i] = i -20;
	}
	std::vector<double> xs2(xsa2, xsa2 + sizeof(xsa2) / sizeof(double));

	double ysa2[20];

	for (int j = 0; j < 19; j++)
	{
		ysa2[j] = calculate_hyperbola_function(function, xsa2[j]);
	}
	ysa2[19] = calculate_hyperbola_function(function, xsa2[19]);
	std::vector<double> ys2(ysa2, ysa2 + sizeof(ysa2) / sizeof(double));

	ScatterPlotSeries* series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &xs;
	series->ys = &ys;
	series->linearInterpolation = true;
	series->lineType = toVector(L"dashed");
	series->lineThickness = 2;
	series->color = GetGray(0.3);


	ScatterPlotSettings* settings = GetDefaultScatterPlotSettings();
	settings->width = 1000;
	settings->height = 800;
	settings->autoBoundaries = true;
	settings->autoPadding = false;
	settings->yPadding = 90;
	settings->xPadding = 90;
	settings->title = toVector(L"+");
	settings->xLabel = toVector(L"X axis");
	settings->yLabel = toVector(L"Y axis");
	settings->scatterPlotSeries->push_back(series);

	ScatterPlotSeries* series2 = GetDefaultScatterPlotSeriesSettings();
	series2->xs = &xs2;
	series2->ys = &ys2;
	series2->linearInterpolation = true;
	series2->lineType = toVector(L"dashed");
	series2->lineThickness = 2;
	series2->color = GetGray(0.3);


	ScatterPlotSettings* settings2 = GetDefaultScatterPlotSettings();
	settings2->width = 1000;
	settings2->height = 800;
	settings2->autoBoundaries = true;
	settings2->autoPadding = false;
	settings2->yPadding = 90;
	settings2->xPadding = 90;
	settings2->title = toVector(L"-");
	settings2->xLabel = toVector(L"X axis");
	settings2->yLabel = toVector(L"Y axis");
	settings2->scatterPlotSeries->push_back(series2);

	success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);
	success = success && DrawScatterPlotFromSettings(canvasReference2, settings2, errorMessage);
	if (success) {
		image1 = imageReference->image;
		image2 = canvasReference2->image;
		DrawImageOnImage(combined, image1, 0, 0);
		DrawImageOnImage(combined, image2, 1000, 0);
		std::vector<double>* pngdata = ConvertToPNG(combined);
		WriteToFile(pngdata, "Hyperbola/hyperbola.png");
		DeleteImage(combined);
	}
	else {
		std::cerr << "Error: ";
		for (wchar_t c : *errorMessage->string) {
			std::wcerr << c;
		}
		std::cerr << std::endl;
	}

	FreeAllocations();

	return success ? 0 : 1;
}
