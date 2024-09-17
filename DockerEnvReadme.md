# C++ Development Environment with CMake and Matplotlib for C++ (using `matplotlibcpp`)

---

### Overview

This project provides a Docker-based C++ development environment designed to run and build C++ applications using CMake and the `matplotlibcpp` library for graph plotting. The environment is based on a lightweight `debian:bullseye-slim` image and comes pre-configured with essential tools like GCC, CMake, Python3, and the necessary Python packages (`matplotlib` and `numpy`).

The project includes a simple C++ example (`test.cpp`) that demonstrates the use of the `matplotlibcpp` library to create plots. Once you run a container using this image it'll automatically compile a sample file which is plotting a simple graph using matplotlib.

Now since ther eis no way to see the graph I have saved it into a png file which can be opened in VsCode. 

In order to do that follow [this](#opening-the-running-container-in-vscode) command.

---

### Features
- **C++ Development Tools**: Includes GCC and CMake to compile and build C++ applications.
- **Matplotlib for C++**: Pre-configured to use the `matplotlibcpp` library for plotting graphs in C++.
- **Lightweight Base Image**: Built on top of `debian:bullseye-slim` for a minimal and efficient environment.

---

### Pulling the Docker Image

This Docker image is hosted on DockerHub, allowing you to quickly set up the environment without having to build it yourself. You can pull the image by running the following command:

```bash
docker pull <priyanshuhaldar007>/cpp_machine_learning:latest
```

Replace `<priyanshuhaldar007>` with the actual DockerHub username.

---

### How to Use This Image

1. **Pull the Image**:
   ```bash
   docker pull <priyanshuhaldar007>/cpp_machine_learning:latest
   ```

2. **Run the Container**:
   You can start an interactive container using:
   ```bash
   docker run -it <priyanshuhaldar007>/cpp_machine_learning
   ```

3. **Mount a Local Directory (Optional)**:
   To work with your own local project, mount your project directory to `/app` inside the container:
   ```bash
   docker run -it -v /path/to/your/project:/app <priyanshuhaldar007>/cpp_machine_learning
   ```

---

### Opening the running container in VsCode

1. Click on "**Open a Remote Window**" button on the bottom left corner of VsCode window.

2. Then select the option "**Attach it to a running container**".

3. Select the container which is built using the image pulled from dockerhub.

4. Expand the "**Explorer**" Pannel from the "**Primary Side Bar**".

5. Click on "**Open folder**" button and navigate to `app/` folder in the root directory.

6. Then you'll be able to see the image named `plot.png` inside the build folder.

### Project Structure

- **CMakeLists.txt**: The CMake configuration file used to configure and generate the build system.
- **Dockerfile**: The Dockerfile that defines the environment setup.
- **src/test.cpp**: The example C++ program that uses `matplotlibcpp` to create a plot.
- **include/matplotlibcpp.h**: Header file for the `matplotlibcpp` library, which wraps around Python’s Matplotlib to allow plotting in C++.

---

### Example C++ Code (using `matplotlibcpp`)

Here is a basic example of how to use `matplotlibcpp` in the project’s C++ code:

```cpp
#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {1, 4, 9, 16, 25};

    plt::plot(x, y);
    plt::show();

    return 0;
}
```

This program will plot the graph of `y = x^2`.

---