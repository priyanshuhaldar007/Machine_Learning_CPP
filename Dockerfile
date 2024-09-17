# Use a lightweight base image
FROM debian:bullseye-slim

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install essential packages in one go and clean up
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    g++ \
    cmake \
    git \
    python3 \
    python3-dev \
    python3-pip \
    --no-install-recommends && \
    rm -rf /var/lib/apt/lists/*

# Install matplotlib and numpy with version pinning
RUN pip3 install matplotlib==3.9.2 numpy==1.26.4

# Set the working directory inside the container
WORKDIR /app

# Copy the local project files to the container
COPY . .

WORKDIR /app/build

RUN cmake ..

RUN make

RUN ./test

# Default command to keep the container running in interactive mode
CMD ["/bin/bash"]
