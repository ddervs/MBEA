import numpy as np
import matplotlib.pyplot as plt


improved_data = np.load("improved_results.npy")
standard_data = np.load("standard_results.npy")

m_values = np.load("m_values.npy")
n_values = np.load("n_values.npy")
p_values = np.load("p_values.npy")
num_reps = np.load("num_reps.npy")

plt.rc('text', usetex=True)
plt.rc('font', family='serif', serif='cm10')

for p_idx in range(0, p_values.size):

    # One plot for each value of p
    num_vertices_arr = np.zeros((m_values.size * n_values.size), dtype=np.int)
    improved_mean_time_arr = np.zeros((m_values.size * n_values.size))
    improved_error_arr = np.zeros((m_values.size * n_values.size))
    standard_mean_time_arr = np.zeros((m_values.size * n_values.size))
    standard_error_arr = np.zeros((m_values.size * n_values.size))

    for m_idx in range(0, m_values.size):
        for n_idx in range(0, n_values.size):

            num_vertices = m_values[m_idx] + n_values[n_idx]
            num_vertices_arr[m_idx * n_values.size + n_idx] = num_vertices

            # improved
            improved_mean_time = np.mean(improved_data[m_idx][n_idx][p_idx][:])
            improved_mean_time_arr[m_idx * n_values.size + n_idx]  = improved_mean_time
            improved_std_time = np.std(improved_data[m_idx][n_idx][p_idx][:])
            improved_error = improved_std_time / np.sqrt(num_vertices)
            improved_error_arr[m_idx * n_values.size + n_idx] = improved_error

            # standard
            standard_mean_time = np.mean(standard_data[m_idx][n_idx][p_idx][:])
            standard_mean_time_arr[m_idx * n_values.size + n_idx] = standard_mean_time
            standard_std_time = np.std(standard_data[m_idx][n_idx][p_idx][:])
            standard_error = standard_std_time / np.sqrt(num_vertices)
            standard_error_arr[m_idx * n_values.size + n_idx] = standard_error


    ## plot

    #sort indices
    sorted_indices = np.argsort(num_vertices_arr)
    num_vertices_arr = num_vertices_arr[sorted_indices]
    standard_error_arr = standard_error_arr[sorted_indices]
    standard_mean_time_arr = standard_mean_time_arr[sorted_indices]
    improved_error_arr = improved_error_arr[sorted_indices]
    improved_mean_time_arr = improved_mean_time_arr[sorted_indices]

    #remove duplicates (warning this discard some data)
    to_delete = []
    for i in range(0, num_vertices_arr.size - 1):
        if num_vertices_arr[i] == num_vertices_arr[i+1]:
            to_delete.append(i)

    num_vertices_arr = np.delete(num_vertices_arr, to_delete)
    standard_error_arr = np.delete(standard_error_arr, to_delete)
    standard_mean_time_arr = np.delete(standard_mean_time_arr, to_delete)
    improved_error_arr = np.delete(improved_error_arr, to_delete)
    improved_mean_time_arr = np.delete(improved_mean_time_arr, to_delete)


    plt.errorbar(num_vertices_arr, standard_mean_time_arr, yerr=standard_error_arr, label=r'MBEA', color='gray', linestyle='--')
    plt.errorbar(num_vertices_arr, improved_mean_time_arr, yerr=improved_error_arr, label=r'iMBEA', color='black')
    plt.xlim([np.min(num_vertices_arr) - 0.5, np.max(num_vertices_arr) + 0.5 ])
    plt.xlabel(r'\textrm{Number of vertices}')
    plt.ylabel(r'\textrm{time /s}')
    latex_p = r'${\LARGE p ='+str(p_values[p_idx])+'}$'
    legend = plt.legend(loc="upper left", bbox_to_anchor=(0, 1), title=latex_p)
    legend.get_title().set_fontsize('18')
    plotname = 'p_is_' + str(p_values[p_idx]) + '.pdf'
    plt.savefig(plotname, bbox_inches='tight')

    plt.close()