Find what you need faster … Home is your new landing page and surfaces your most relevant files and folders
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    int n, m, i, j, k;

    // Open a file for reading
    std::ifstream inFile("data.txt");

    // Check if the file is opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;  // Return an error code
    }

    // Read the number of processes and resources
    inFile >> n >> m;

    // Read Allocation Matrix
    std::vector<std::vector<int>> alloc(n, std::vector<int>(m, 0));
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            inFile >> alloc[i][j];
        }
    }

    // Read MAX Matrix
    std::vector<std::vector<int>> max(n, std::vector<int>(m, 0));
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            inFile >> max[i][j];
        }
    }

    // Read Available Resources
    std::vector<int> avail(m, 0);
    for (i = 0; i < m; ++i) {
        inFile >> avail[i];
    }

    // Close the file
    inFile.close();

// Banker's Algorithm
std::vector<int> f(n, 0), ans(n, 0);
int ind = 0;

// Initialize the 'need' matrix, representing the remaining resources needed for each process
std::vector<std::vector<int>> need(n, std::vector<int>(m, 0));
for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
        need[i][j] = max[i][j] - alloc[i][j];
}

int safe = 1;

// Iterate through processes to find a safe execution sequence
for (k = 0; k < n; k++) {
    int selected = -1;

    // Iterate through processes to find one that can be executed safely
    for (i = 0; i < n; i++) {
        if (f[i] == 0) { // Check if the process is not yet executed
            int flag = 1;

            // Check if the process can be executed safely by comparing its 'need' with available resources
            for (j = 0; j < m; j++) {
                if (need[i][j] > avail[j]) {
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                selected = i; // Select the process
                break;
            }
        }
    }

    // Check if a process was selected
    if (selected == -1) {
        safe = 0; // No safe sequence found, set the flag to 0
        break;
    }

    // Execute the selected process
    ans[ind++] = selected;

    // Update available resources after executing the process
    for (j = 0; j < m; j++)
        avail[j] += alloc[selected][j];

    // Mark the selected process as executed
    f[selected] = 1;
}

// Check if a safe sequence was found and print the sequence or an error message accordingly
if (safe) {
    std::cout << "Following is the SAFE Sequence" << std::endl;
    for (i = 0; i < n - 1; i++)
        std::cout << " P" << ans[i] << " ->";
    std::cout << " P" << ans[n - 1] << std::endl;
} else {
    std::cout << "The given sequence is not safe" << std::endl;
}

// Return 0 to indicate successful execution
return 0;
}
