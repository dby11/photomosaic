# photomosaic

This is a repo for a photomosaic app which uses an image and photo database provided by the user. It assembles a reasonable likeness of the original image using scaled versions of other photos in the database and matching photos in the database as closely as possible by color to parts of the original image. 

It uses C++11 standards and the QT 5.7 compiler. Example database downloaded from Artensoft.com/ArtensoftPhotoMosaicWizard/photobases.php for personal use and demonstration of functionality.

Example YouTube demo: https://youtu.be/-qD1BPQaKbg

Known issues and next steps:
	<ul><li> Algorithm improvement and duplicate reduction</li>
	<li> Some images in database are null</li>
	<li> Support for image formats other than PNG</li>
	<li> UI improvements</li>
	<li> Unknown errors in QT output - doesn't impact program but worth investigating</li></ul>

Done as a project by Derek Yen for PIC 10C Fall 2016.
