#pragma once

#include <QVector>
#include <QString>
#include "TNeuron.h"
#include "compressFunctions.h"

class TNeuronLayer
{
private:
	ExpSigmoidal mActivationFunction;
	QList<TNeuron> mNeurons;
	QVector<double> mLayerOut;
public:
	TNeuronLayer(ExpSigmoidal &activationFunction
				 , int dimOfInput
				 , int dimOfLayer);
	TNeuronLayer(const QDomElement &layer);
	void addNeuron(const TNeuron &neuron);
	const int getDimension() const;
	void setActivationFunction(ExpSigmoidal &newActivationFunction);
	//вычисление выхода слоя
	QVector<double> getResult(const QVector<double> &input);
	QVector<double> showResult() const;
	//обучение слоя методом обратного распространения ошибки
	QVector<double> learn(QVector<double> &correction, const QVector<double> &input);

	QDomElement save(QDomDocument &mlp, int layerNumber);
};