FROM ubuntu:22.04 as build

# --- basic package installation ---
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        git \
        pkgconf \
        apt-utils \
        python3 \
        python3-pip \
        wget
RUN pip install ninja ninja_syntax prettytable colorama capstone==5.0.1 pyelftools pylibyaml PyYAML

# --- wibo installation ---
RUN wget https://github.com/decompals/wibo/releases/latest/download/wibo
RUN install ./wibo /usr/bin

# --- devkitpro installation ---
RUN wget https://apt.devkitpro.org/install-devkitpro-pacman
RUN chmod +x install-devkitpro-pacman
## assume yes for in-script apt commands
RUN sed -ie 's/^apt-get.*$/& -y/g' install-devkitpro-pacman
## now do dkp-pacman installation, then install devkitPPC
RUN ./install-devkitpro-pacman
RUN dkp-pacman -S devkitPPC --noconfirm

# --- stage libreultra headers ---
RUN git clone https://github.com/n64decomp/libreultra.git libreultra
## remove the things we don't need
RUN rm -rf libreultra/src/ libreultra/tools/ && rm libreultra/.gitignore libreultra/Makefile
## modify Gpopmtx's param member to be unsigned int
RUN cd libreultra/include/2.0I/PR/ && sed -i 's/unsigned char       param:8;/unsigned int   param:8;/g' gbi.h
## move headers to /N64_SDK/ultra/usr/ and delete the old directory
RUN mkdir -p /N64_SDK/ultra/usr/ && mv libreultra/include/ /N64_SDK/ultra/usr/ && rm -r libreultra

RUN mkdir /ac-decomp
WORKDIR /ac-decomp
ENV PATH="/ac-decomp/tools:${PATH}"
ENV N64_SDK="/N64_SDK"

CMD echo 'usage: docker run -dit --rm --mount type=bind,source="$(pwd)",destination=/ac-decomp ac-decomp\n'
CMD bash
