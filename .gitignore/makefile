
# Author: Kyle Wollman
# Date: 3/21/2017
# Final Project makefile
  
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS +=  -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = $(SRCS: .cpp = .o) 

SRCS = Brewery.cpp BucketFactory.cpp Character.cpp DairyFarm.cpp Destination.cpp FerrariDealer.cpp Game.cpp Germany.cpp Home.cpp\
       IceCastle.cpp Italy.cpp Kitchen.cpp Location.cpp NorthPole.cpp PastaShop.cpp PortalTransitAuthority.cpp Space.cpp\
       WheatFarm.cpp Wisconsin.cpp YeastFactory.cpp finalMain.cpp
		  
HEADERS = Brewery.hpp BucketFactory.hpp Character.hpp DairyFarm.hpp Destination.hpp FerrariDealer.hpp Game.hpp Germany.hpp Home.hpp\
          IceCastle.hpp Italy.hpp Kitchen.hpp Location.hpp NorthPole.hpp PastaShop.hpp PortalTransitAuthority.hpp Space.hpp\
          verify.hpp WheatFarm.hpp Wisconsin.hpp YeastFactory.hpp

all : $(OBJS)
	$(CXX) $(OBJS) -o final 

$(OBJS) : $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean: 
	rm -f *.o final
