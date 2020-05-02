// ----------------------------------------------------------------
// The contents of this file are distributed under the CC0 license.
// See http://creativecommons.org/publicdomain/zero/1.0/
// ----------------------------------------------------------------

#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <exception>
#include <string>
#include <memory>
#include "error.h"
#include "string.h"
#include "rand.h"
#include "matrix.h"
#include "supervised.h"
#include "baseline.h"
#include "layerlinear.h"
#include "layertanh.h"
#include "NeuralNet.h"
#include "nomcat.h"

using std::cout;
using std::cerr;
using std::string;
using std::auto_ptr;

int main(int argc, char *argv[])
{
	enableFloatingPointExceptions();
	int ret = 1;
	try
	{
		/*
			In order to get this thing to work well, you have a couple options:
				1.) Normalize the data. Neural networks tend to respond better when all attributes are normalized.
					Pixel values can be anything between 0 and 255, so divide the value of each pixel by 256 to shrink this range to [0, 0.99].
					(Hint: you can do this in two very short lines of code. Check the Matrix class.)
				2.) Add more layers. More layers make the neural net more "powerful", so it's able to learn more complicated functions.
				3.) Alternate between linear layers and non-linear layers. Non-linear layers make the model more "flexible".
				4.) Change the learning rate. The learning rate (alpha in NeuralNet.cpp) is called a hyperparameter because it is
					something you set, not something the network must learn. If alpha is too high, the network will
					never converge. If alpha is too low, the network will take forever to learn.
				5.) Add momentum (mu in NeuralNet.cpp). Momentum can sometimes increase the speed of convergence because it results #include
					a "smoother" learning curve.
				6.) Increase the number of epochs. 1 epoch = 1 pass over the training data. Currently that number is set to 3, which is probably not high enough.
				7.) Train in batches instead of one image at a time. Set the batch size to a number higher than 1.
		*/

		Rand* rng = new Rand(time(NULL));

		Matrix train_feat;
		train_feat.loadARFF("data/train_feat.arff");
		Matrix train_lab;
		train_lab.loadARFF("data/train_lab.arff");
		Matrix test_feat;
		test_feat.loadARFF("data/test_feat.arff");
		Matrix test_lab;
		test_lab.loadARFF("data/test_lab.arff");

		Matrix train_lab_1h(train_lab.rows(), 10);
		train_lab_1h.fill(0.0);
		Matrix test_lab_1h(test_lab.rows(), 10);
		test_lab_1h.fill(0.0);

		//Normalize here

		//Transform the labels to 1-hot
		for(size_t i = 0; i < train_lab.rows(); i++)
			for(size_t j = 0; j < 10; j++)
				if(train_lab[i][0] == j)
					train_lab_1h[i][j] = 1;

		for(size_t i = 0; i < test_lab.rows(); i++)
			for(size_t j = 0; j < 10; j++)
				if(test_lab[i][0] == j)
					test_lab_1h[i][j] = 1;

		size_t num_features = train_feat.cols();
		size_t num_labels = train_lab_1h.cols();

		//Create neural net
		NeuralNet nn;

		//Define the topology
		nn.addLayer(new LayerLinear(num_features,num_labels));

		//Set learning rate and init weights
		nn.setLearningRate(1);
		nn.initWeights(rng);

		cout << "Misclassifications:\n";

		//Train the model
		for(int i = 0; i < 3; i++)
		{
			nn.train(train_feat, train_lab_1h);
			cout << "Epoch " << i << ": " << nn.countMisclassifications(test_feat, test_lab_1h) << std::endl;
		}


		ret = 0;
	}
	catch(const std::exception& e)
	{
		cerr << "An error occurred: " << e.what() << "\n";
	}
	cout.flush();
	cerr.flush();

	return ret;
}
