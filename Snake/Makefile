NAME			=	Snake

OBJDIR			=	obj

CXX				=	g++

ENGINEPATH		=	../SpxEngine

GAMEPATH		=	src

DEBUGFLAGS		=	-g

RELEASEFLAGS	=	-O3 -D _NO_TEST_

WARNINGS		=	-Wall -Wshadow -Wswitch-enum -Wundef	\
					-Wredundant-decls -Wcast-align -Winline	\
					-Wzero-as-null-pointer-constant			\
					-Wnon-virtual-dtor -Wpedantic			\
					-Wmissing-include-dirs -Winvalid-pch

EXTRAWFLAGS		=	-Wextra -Wfloat-equal -Wswitch-default	\
					-Wunreachable-code						\
					-Wmissing-declarations					\
#					-Weffc++

DEFAULTFLAGS	=	-std=c++14 -fexceptions $(WARNINGS)

# the file Makefile.eng contains
# ENGINEDIRS variable
# ENGINEDEPEND variable
include $(ENGINEPATH)/Makefile.eng

ENGINEDIRS		:=	$(addprefix $(ENGINEPATH)/, $(ENGINEDIRS))

SRDIRS			:=	$(GAMEPATH)								\
#					$(GAMEPATH)/Animations					\
#					$(GAMEPATH)/GameObjects					\
#					$(GAMEPATH)/Behaviours					\
#					$(ENGINEDIRS)

INCLUDEPFLAGS	:=	$(addprefix -I, $(SRDIRS))				\
					$(addprefix -I, $(ENGINEDIRS))

CXXFLAGS		=	$(DEFAULTFLAGS) $(INCLUDEPFLAGS)

LDLIBS			=	-lspxengine								\
					$(ENGINEDEPEND)


LDFLAGS			=	-L$(ENGINEPATH)

SRC				:=	$(wildcard $(addsuffix /*.cpp, $(SRDIRS)))

OBJ				:=	$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

RM				=	/bin/rm -f

MKDIR			=	/bin/mkdir -p

.PHONY: all clean fclean re debug release extrawarnings engine

$(OBJDIR)/%.o: %.cpp
	$(MKDIR) $(dir $@)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(NAME): engine $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

all: $(NAME)

engine:
	$(MAKE) -C $(ENGINEPATH) $(MAKECMDGOALS)

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: $(NAME)

extrawarnings: CXXFLAGS += $(EXTRAWFLAGS)
extrawarnings: debug

release: CXXFLAGS += $(RELEASEFLAGS)
release: $(NAME)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
