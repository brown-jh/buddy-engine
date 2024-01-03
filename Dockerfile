# Use NVIDIA CUDA base image
FROM nvidia/cuda:12.3.1-devel-ubuntu22.04

# Update packages and install required dependencies
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    libglfw3 libglfw3-dev libglm-dev xorg-dev libglu1-mesa-dev curl wget
    
RUN wget -qO- https://packages.lunarg.com/lunarg-signing-key-pub.asc | tee /etc/apt/trusted.gpg.d/lunarg.asc && \
    wget -qO /etc/apt/sources.list.d/lunarg-vulkan-jammy.list http://packages.lunarg.com/vulkan/lunarg-vulkan-jammy.list
    
RUN apt update && \
    apt install -y vulkan-sdk

# Set app directory
WORKDIR /app

# Your additional configurations, commands, and code can go here

# Entry point or default command to run when the container starts
CMD ["/bin/bash"]
