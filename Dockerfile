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
## TODO: Don't hardcode python deps, and install them from requirements.txt instead where possible.
RUN pip install ninja ninja_syntax prettytable colorama capstone==5.0.1 pyelftools pylibyaml PyYAML watchdog python-Levenshtein cxxfilt

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

# --- stage ultralib headers ---
RUN mkdir -p /N64_SDK/ultra/usr/
RUN git clone https://github.com/decompals/ultralib.git /N64_SDK/ultra/usr/
## modify Gpopmtx's param member to be unsigned int
RUN sed -i 's/unsigned char	param:8;/unsigned int	param:8;/g' /N64_SDK/ultra/usr/include/PR/gbi.h

RUN mkdir /ac-decomp
WORKDIR /ac-decomp
ENV PATH="/ac-decomp/tools:${PATH}"
ENV N64_SDK="/N64_SDK"
ENV DEVKITPPC="/opt/devkitpro/devkitPPC"

CMD echo 'usage: docker run -dit --rm --mount type=bind,source="$(pwd)",destination=/ac-decomp ac-decomp \n' \
         'see https://github.com/Prakxo/ac-decomp/blob/master/README.md for advanced usage'
