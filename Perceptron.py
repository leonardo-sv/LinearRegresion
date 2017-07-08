'''
Created on 12/07/2016

@author: Fabiana
'''

# ------ Perceptron implementado para disciplina de IA -----#
import numpy as np

class Perceptron(object):
    '''
    classdocs
    '''


    def __init__(self,  InputSize, m):
        '''
        Constructor da Classe
        '''
        self.inputSize = InputSize
        self.m = m
        self.theta = np.random.rand(self.inputSize + 1)     
        self.h0 = 0
        self.X = 0
        
    def adicionaBiasEntrada(self, inputX):
        bias = np.ones(1)
        x = np.append(bias,inputX)
        return x
    
    def ativacao(self, z0):
        if z0 < 0:
            return 1
        else:
            return 0
    
    def propagacaoValores(self, inputX):
        self.X = self.adicionaBiasEntrada(inputX)
        #print "self.X ", self.X
        z0 = np.dot(self.X, self.theta.T)
        #print "Z ", z0
        self.h0 = self.ativacao(z0)
    
    def trainer(self, inputX, y, leaningRate):
        
        self.propagacaoValores(inputX)
        erro = self.h0 - y
        self.theta += leaningRate * erro * self.X
                
        
        
def main():
    # Entradas para o treinamento
    X = np.array(([0,0], [0,1], [1,0], [1,1]), dtype= float)
    y = np.array(([0],[0],[0],[1]), dtype = float)
    
    #tamanho da entrada
    inputSize = 2
    #numero de exemplos 
    m = len(X)
    #taxa de aprendizado
    leaningRate = 0.1
    epochs = 100
    perceptron = Perceptron(inputSize, m)
    print'\nValores Iniciais Theta '
    print perceptron.theta
    #print 'Custo Inicial ', perceptron.costFunction(X, y)
    print '\nRealizando Treinamento ...\n'
    
    for interacoes in range(epochs):
        print 'Interacao ', interacoes
        j = 0
        
        for inputX in X:
            perceptron.trainer(inputX, y[j], leaningRate)
            j += 1
        
        
    print '\n#--- Rede Depois de treinada --- #\nValores de Theta:'
    print perceptron.theta
    print'\n#-- Teste -- #'
    for x in X:
        print 'X ', x
        perceptron.propagacaoValores(x)
        print 'Resultado ', perceptron.h0
if __name__ == '__main__':
    main()
