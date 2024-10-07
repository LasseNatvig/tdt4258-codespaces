# TDT4258 C Programming

This repository contains a C programming environment for use in the course TDT4258. It lets you write, compile, and debug C programs in a VSCode-like environment straight from your web browser, or in VSCode on your local machine.

## Getting Started

To use this environment, you can either use GitHub Codespaces in a web browser, or use a VSCode on your local computer with a Dev Container.

### GitHub Codespaces in a web browser

1. Create a GitHub account if you don't already have one.

1. Create a new repository using this template:

   - Click the "Use this template" button at the top right of this page.
   - Select the "Create a new repository" option.
   - Give your repository a name.
   - **Select the "Private" option**. This is very important, as it prevents others students from seeing (and potentially plagiarizing) your code.
   - Click the "Create repository" button.

1. Launch a Codespace:

   - Go to your own repository that you just created.
   - Click the green "Code" button.
   - Select the "Codespaces" tab.
   - Click "Create codespace on main".

1. Wait for the Codespace to build. This may take a few minutes the first time.

1. Once the Codespace is ready, you'll see a VSCode interface in your browser. You may get a popup saying "There are task errors. See the output for details.". You can safely ignore this warning!

### VSCode Dev Container on your local machine

1. Install Docker Desktop and VSCode.

1. Install the "Dev Containers" extension in VSCode.

1. Clone this repository and open it in VSCode. You should be prompted with a dialog asking if you want to develop in a container. Click "Reopen in Container".

## Compiling and running programs

Open the terminal within VSCode (Ctrl + D or Cmd + D) and try compiling and running the example program:

```bash
# Compile the program
clang example.c -o example

# Run the program
./example
```

### Graphics

To compile programs using SDL2 graphics, some additional compiler flags are needed:

```bash
# Compile the program with SDL2
clang sdl2-demo.c -o sdl2-demo $(sdl2-config --cflags --libs)

# Run the program
./sdl2-demo
```

To see the GUI of your running program, go to the "Ports" tab next to the terminal in VSCode, and find the URL listed under "Forwarded Address". Open this URL in a web browser and click "Connect".

## Debugging

To debug a program, you can use the VSCode debugger. To start debugging the current C file, open the debugger pane in VSCode (the "play" button in the left sidebar) and click the "Run and Debug" button.

In debug mode, you can set breakpoints in your code by clicking on the line number in the left margin. You can then inspect your variables in the sidebar.

## Saving your work

You can use Git when you work in a Codespace just as you would in a local environment. You can either run Git commands in the terminal or use the VSCode Git integration found in the sidebar.

> [!WARNING]
> GitHub Codespaces will be deleted after 30 days of inactivity. We recommend commiting and pushing your changes regularly to avoid losing your work.
