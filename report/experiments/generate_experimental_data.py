import numpy as np
import os
import time

def erdos_renyi_bipartite_graph(m, n, p):
    """
    Makes an m x n numpy {0-1}-array where each element has probability p
    of containing a 1, (1-p) probability of containing 0.
    :param m: number of vertices in left bipartition.
    :param n: number of vertices in right bipartition.
    :param p: probabiliy of edge existing.
    :return:
    """
    samples = np.random.rand(m,n)
    mask = (samples <= p)
    return mask.astype(int)


m_values = np.array([5, 10, 15, 20])
n_values = np.array([10, 15, 20, 25])
p_values = np.array([0.1, 0.25, 0.5, 0.75, 0.9])
num_reps = 20

counter = 0

time_vals_improved = np.zeros((m_values.size, n_values.size, p_values.size, num_reps))
time_vals_standard = np.zeros((m_values.size, n_values.size, p_values.size, num_reps))

num_graphs = time_vals_improved.size

tmp_filename = "tempfile.txt"

for m_idx in range(0, m_values.size):
    for n_idx in range (0, n_values.size):
        for p_idx in range(0, p_values.size):
                for t in range(0, num_reps):
                    counter += 1
                    to_save = erdos_renyi_bipartite_graph(m_values[m_idx], n_values[n_idx], p_values[p_idx])
                    np.savetxt(tmp_filename, to_save, fmt="%d")

                    # standard algo
                    # improved algo
                    start_time = time.time()
                    #os.system("./MBEA tempfile.txt standard")
                    os.system("./MBEA tempfile.txt standard >> /dev/null")
                    end_time = time.time()
                    elapsed = end_time - start_time
                    time_vals_standard[m_idx, n_idx, p_idx, t] = elapsed

                    # improved algo
                    start_time = time.time()
                    #os.system("./MBEA tempfile.txt")
                    os.system("./MBEA tempfile.txt >> /dev/null")
                    end_time = time.time()
                    elapsed = end_time - start_time
                    time_vals_improved[m_idx, n_idx, p_idx, t] = elapsed

                    print str(counter) + " out of " + str(num_graphs) + " graphs analysed"

os.system("rm tempfile.txt")

np.save("standard_results", time_vals_improved)
np.save("improved_results", time_vals_standard)
np.save("m_values", m_values)
np.save("n_values", n_values)
np.save("p_values", p_values)
np.save("num_reps", num_reps)