.PHONY:clean cleanall
CC = g++
EXEC = mmo
# LIBOBJ = imgui.o imgui_demo.o imgui_draw.o imgui_widgets.o imgui_impl_glfw.o imgui_impl_opengl3.o imgui_patch.o
LIBOBJ = lib.o shader.o 
COREOBJ = mmo.o cube.o
TOOLSOBJ = std_image.o
LIBOBJS = $(addprefix lib/, $(LIBOBJ))
COREOBJS = $(addprefix core/, $(COREOBJ))
TOOLSOBJS = $(addprefix tools/, $(TOOLSOBJ))
OBJS = $(LIBOBJS) $(COREOBJS) $(TOOLSOBJS) main.o
%.o:%.cpp
	$(CC) -I./imgui/ -I./src/ -I./core/ -I./lib/ -I./GUI/ -I./tools -c $< -o $@ -std=c++11 
$(EXEC):$(OBJS)
	$(CC) $(OBJS) -lglfw -lGLEW -lGL -o $(EXEC)
cleanall:clean
	rm $(EXEC)
clean:
	rm $(OBJS)
