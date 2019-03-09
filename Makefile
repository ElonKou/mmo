.PHONY:clean cleanall
CC = g++
EXEC = mmo
# LIBOBJ = imgui.o imgui_demo.o imgui_draw.o imgui_widgets.o imgui_impl_glfw.o imgui_impl_opengl3.o imgui_patch.o
LIBOBJ = lib.o shader.o
COREOBJ = mmo.o cube.o
LIBOBJS = $(addprefix lib/, $(LIBOBJ))
COREOBJS = $(addprefix core/, $(COREOBJ))
OBJS = $(LIBOBJS) $(COREOBJS) main.o
%.o:%.cpp
	$(CC) -I./imgui/ -I./src/ -I./core/ -I./lib/ -I ./GUI/ -c $< -o $@ -std=c++11 
$(EXEC):$(OBJS)
	$(CC) $(OBJS) -lglfw -lGLEW -lGL -o $(EXEC)
cleanall:clean
	rm $(EXEC)
clean:
	rm $(OBJS)
