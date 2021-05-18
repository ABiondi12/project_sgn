from ransac import *
import numpy as np
import pylab

n_samples = 500
n_inputs = 1
n_outputs = 1

r01_true = 5000
r01_mis = r01_true + 100 *  np.random.random((n_samples,n_outputs))

N = np.shape(r01_mis)[0]  #Get the size of the random data vector

# Creates the matrix for the ransac_fit
regressor = np.ones([N,1])
print('regressor', regressor.shape)
print('r01 shape', r01_mis.shape)
print(type(r01_mis))

#Add outliers
if 1:
	n_outliers = 100
	all_idxs = numpy.arange (N)
	numpy.random.shuffle(all_idxs)
	outlier_idxs = all_idxs[:n_outliers]
	non_outlier_idxs = all_idxs[n_outliers:]
	r01_mis[outlier_idxs] = 50*np.random.random()

	
	

all_data = np.hstack( (regressor, r01_mis) )
input_columns = range(n_inputs) # the first columns of the array
output_columns = [n_inputs+i for i in range(n_outputs)] # the last columns of the array
debug = False
model = LinearLeastSquaresModel(input_columns,output_columns,debug=debug)

linear_fit,resids,rank,s = scipy.linalg.lstsq(all_data[:,input_columns],
                                                  all_data[:,output_columns])
print(type(all_data))                                           
ransac_fit, ransac_data = ransac(all_data,model,
                                     50, 1000, 1e5, 50, # misc. parameters
                                     debug=debug,return_all=True)
                                                             
                                                  
print('linear fit', linear_fit)
print('ransac fit', ransac_fit)
print('valor_medio', r01_mis.sum()/n_samples)


pylab.plot(np.arange(n_samples), r01_mis[:,0], 'k.',label='data')  
pylab.plot(np.arange(n_samples), np.ones(n_samples)*ransac_fit[0][0], 'r-', label='ransac fit')

pylab.show()

print('ransac_data_type', type(ransac_data))
print('ransac_fit type', type(ransac_fit))












