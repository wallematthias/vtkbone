/*=========================================================================

  Copyright 2010-2016, Numerics88 Solutions Ltd.
  http://www.numerics88.com/

  Copyright (c) Eric Nodwell and Steven K. Boyd
  See Copyright.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.
=========================================================================*/

// .NAME vtkboneMaterialArray - An abstract base class for materials of
//    materials of the same type
//
// .SECTION Description
// Note that although this represents a collection of similar materials,
// MaterialArray is not implemented an array of material objects, but as
// a single object that inherits from vtkboneMaterial, and that stores
// arrays of material properties. This more closely matches how material
// arrays are stored in n88model files, and also how they are employed
// by the solver.
//
// .SECTION See Also
// vtkboneMaterial

#ifndef __vtkboneMaterialArray_h
#define __vtkboneMaterialArray_h

#include "vtkboneMaterial.h"
#include "vtkboneWin32Header.h"

class VTKBONE_EXPORT vtkboneMaterialArray : public vtkboneMaterial
  {
  public:
    static vtkboneMaterialArray* New();
    vtkTypeMacro(vtkboneMaterialArray, vtkObject);
    void PrintSelf(ostream& os, vtkIndent indent) override;

    // Description:
    // Destructively re-sizes the arrays.
    virtual void Resize(vtkIdType size);

    // Description:
    // Get the size of the material array (the number of materials).
    virtual vtkIdType GetSize();

  protected:
    vtkboneMaterialArray();
    ~vtkboneMaterialArray();

  private:
    vtkboneMaterialArray(const vtkboneMaterialArray&);  // Not implemented.
    void operator=(const vtkboneMaterialArray&);  // Not implemented.
  };

#endif

