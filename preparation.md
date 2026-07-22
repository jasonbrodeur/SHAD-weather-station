---
layout: default
title: Preparation
nav_order: 2
---

# Preparation
In this workshop, we will build a weather station using simple sensors, the open source [Arduino UNO microcontroller](https://store.arduino.cc/products/arduino-uno-rev3), and the [Ardiuno IDE](https://www.arduino.cc/en/software/) to program it.  

Prior to the workshop, please do the following: 

## 1. Install the Arduino IDE (if compatible)
For this workshop, it is strongly recommended that groups install and use the desktop version of the Arduino IDE (version 2.3.10), which is available for Windows (versions 10 and 11), Linux, and macOS [here](https://www.arduino.cc/en/software/#:~:text=Bring%20Your%20Projects%20to%20Life%20with%20Arduino%20Software). At least one member of each 4-person group needs the IDE installed, but more are better.  

Chromebook users can attempt to install Arduino Cloud via the [Play store](https://www.arduino.cc/en/software/#:~:text=Arduino%20Cloud%20on%20Chromebook); however, this interface differs from the desktop version and may make it more difficult to follow along. 

## 2. Install libraries 

## 1. Download the Arduino IDE 
In this workshop, we will work with QGIS **version 3.44 LTR (Long-term release)** (please note the version). 

### 1.1 Download and install QGIS
QGIS can be downloaded and used on Windows, MacOS, and Linux machines, though the installation instructions differ slightly between operating systems. To download it for your operating system, go [here](https://qgis.org/download/) and follow the installation instructions. **Please do not** install the tablet/phone version for this exercise--these are limited-feature versions of the software and they will not work for our exercises. 

### 1.2 Confirm QGIS is working 
On your computer, open **QGIS Desktop**. If the application loads properly, you should see a default QGIS interface similar to what is shown below: 

<img src="assets/img/qgis-interface.png" alt="QGIS Desktop interface" width="600" style="border: 1px solid darkgrey">

### 1.3 Install plugins
As an open-source project, QGIS has a lot of community-contributed plugins that extend its functionality. Over time, many of these plugins find their way into the core software. We will use a couple of these for our exercise. Follow the instructions below to install them. 
1. Install the NextGIS QuickMapServices plugin:
	- In the top menu bar, click on `Plugins > Manage and Install Plugins`.
	- In the Plugins dialogue box, search for and install the **NextGIS QuickMapServices** plugin. 
	- <img src="assets/img/quickmap-plugin.png" alt="QGIS Plugin window" width="500" style="border: 1px solid darkgrey">
2. Confirm that the plugin works:
    - In the QGIS top menu bar, click on `Web > QuickMapServices`
    - Select to load the OSM Standard webmap by clicking on `OpenStreetMap > OSM Standard`.
    - The OpenStreetMap layer should load so you can zoom into/out of it.
3. Install the qgis2web plugin:
 	- In the top menu bar, click on `Plugins > Manage and Install Plugins`.
	- In the Plugins dialogue box, search for and install the **qgis2web** plugin.

## 2. Download workshop data
In this workshop, we'll learn how to use QGIS by using data that is available from the City of Hamilton [Open Data Portal](https://www.hamilton.ca/city-council/data-maps/open-data). The open data portal has a wide variety of numeric and geospatial data sets that are free and open to use. Many cities and regions now have similar kinds of open data portals, so be sure to check if you're ever doing analyses on your local area!

To download the data: 
- Download ```hamilton-data.zip``` from the [workshop GitHub repository](https://github.com/jasonbrodeur/SHAD-mapping/blob/main/data/hamilton-data.zip) by clicking [this link](https://github.com/jasonbrodeur/SHAD-mapping/raw/main/data/hamilton-data.zip) to download it directly [(bit.ly/shad-ham-data)](https://bit.ly/shad-ham-data).
- Download the data into the directory that you want to use for this workshop (i.e. know where you saved the file and use a folder where you can read/write data)
- **UNZIP THE FILE**. This is very important--otherwise, weird things are going to happen for you.   

<!--
## 2. (Optional) Sign up for a GitHub account
If you would like to publish to the webmap we'll create in this exercise Go to [https://github.com/](https://github.com/) and sign up for an account. Sign into your account prior to the workshop.
-->

**All done?** Move on to the [first lesson](intro-to-GIS).
