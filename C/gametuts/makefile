all : circ1.exe\
      circ2.exe\
      circ3.exe\
      circ4.exe\
      circ5.exe\
      circ6.exe\
      circ7.exe\
      circ8.exe\
      circ9.exe\
      circ10.exe\
      circ11.exe\
      circ12.exe

LIBRARIES = allegro allegro_acodec allegro_audio allegro_color allegro_dialog

#----------------------------------------------------------------------------
CC = gcc

OPTIONS = \
        -O2\
        -ffast-math\
        -fomit-frame-pointer\
        -s

LIBS = $(addprefix -l,$(LIBRARIES))

%exe : %o
	$(CC) -s -o $@ $< $(LIBS)

%o : %c
	$(CC) -c $(OPTIONS) $<

