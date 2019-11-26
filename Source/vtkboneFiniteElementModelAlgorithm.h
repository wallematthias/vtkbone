/*=========================================================================

  Copyright 2010-2016, Numerics88 Solutions Ltd.
  http://www.numerics88.com/

  Copyright (c) Eric Nodwell and Steven K. Boyd
  See Copyright.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.
=========================================================================*/

// .NAME vtkboneFiniteElementModelAlgorithm - Superclass for algorithms that
//  produce only vtkboneFiniteElementModel as output

#ifndef __vtkboneFiniteElementModelAlgorithm_h
#define __vtkboneFiniteElementModelAlgorithm_h

#include "vtkUnstructuredGridAlgorithm.h"
#include "vtkboneWin32Header.h"

// Forward declarations
class vtkDataSet;
class vtkboneFiniteElementModel;

class VTKBONE_EXPORT vtkboneFiniteElementModelAlgorithm : public vtkUnstructuredGridAlgorithm
{
public:
  static vtkboneFiniteElementModelAlgorithm *New();
  vtkTypeMacro(vtkboneFiniteElementModelAlgorithm,vtkUnstructuredGridAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // Get the output data object for a port on this algorithm.
  vtkboneFiniteElementModel* GetOutput();
  vtkboneFiniteElementModel* GetOutput(int);
  virtual void SetOutput(vtkDataObject* d);

  // Description:
  // see vtkAlgorithm for details
  virtual int ProcessRequest(vtkInformation*,
                             vtkInformationVector**,
                             vtkInformationVector*);

  // this method is not recommended for use, but lots of old style filters
  // use it
  vtkDataObject *GetInput(int port);
  vtkDataObject *GetInput() { return this->GetInput(0); };
  vtkboneFiniteElementModel *GetFiniteElementModelInput(int port);

  // Description:
  // Assign a data object as input. Note that this method does not
  // establish a pipeline connection. Use SetInputConnection() to
  // setup a pipeline connection.
  void SetInputData(vtkDataObject *);
  void SetInputData(int, vtkDataObject*);

  // Description:
  // Assign a data object as input. Note that this method does not
  // establish a pipeline connection. Use SetInputConnection() to
  // setup a pipeline connection.
  void AddInputData(vtkDataObject *);
  void AddInputData(int, vtkDataObject*);

protected:
  vtkboneFiniteElementModelAlgorithm();
  ~vtkboneFiniteElementModelAlgorithm();

  // convenience method
  virtual int RequestInformation(vtkInformation* request,
                                 vtkInformationVector** inputVector,
                                 vtkInformationVector* outputVector);

  // Description:
  // This is called by the superclass.
  // This is the method you should override.
  virtual int RequestData(vtkInformation* request,
                          vtkInformationVector** inputVector,
                          vtkInformationVector* outputVector);


  // Description:
  // This is called by the superclass.
  // This is the method you should override.
  virtual int RequestDataObject(vtkInformation*,
                                vtkInformationVector**,
                                vtkInformationVector*);

  // Description:
  // This is called by the superclass.
  // This is the method you should override.
  virtual int RequestUpdateExtent(vtkInformation*,
                                  vtkInformationVector**,
                                  vtkInformationVector*);

  // Description:
  // This method is the old style execute method
  virtual void ExecuteData(vtkDataObject *output);
  virtual void Execute();

  // see algorithm for more info
  virtual int FillOutputPortInformation(int port, vtkInformation* info);
  virtual int FillInputPortInformation(int port, vtkInformation* info);

private:
  vtkboneFiniteElementModelAlgorithm(const vtkboneFiniteElementModelAlgorithm&);  // Not implemented.
  void operator=(const vtkboneFiniteElementModelAlgorithm&);  // Not implemented.
};

#endif
