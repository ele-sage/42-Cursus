<!-- FdF project description + video demo path: FdF_demo.mov -->
# FdF

This project is about creating a simplified 3D graphic representation of a relief landscape. The wireframe model is displayed in a window and the user can rotate the model in 3D space.

The program reads a file containing a map of integers, where each integer represents the height of a point in the landscape. The map is then rendered as a wireframe model, where each point is connected to its neighbors.

The program uses the `minilibx` library to create the window and draw the wireframe model.

## Usage

```shell
make
./fdf test_maps/42.fdf
```

## Demo

<p align="center">
	<img src="https://github.com/ele-sage/42-Cursus/edit/master/Core/FDF/FdF_demo.mov" />
 </p>
