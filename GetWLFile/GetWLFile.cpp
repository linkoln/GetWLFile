#include <iostream>
#include <tchar.h>
#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmdata/dcpxitem.h>
#include <dcmtk/dcmjpeg/djdecode.h>
#include <dcmtk/dcmjpeg/djencode.h>
#include <dcmtk/dcmjpeg/djcodece.h>
#include <dcmtk/dcmjpeg/djrplol.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Iphlpapi.lib")
#pragma comment(lib,"netapi32.lib")

int main()
{
	char uid[100];
	DcmFileFormat fileformat;
	DcmDataset * dataset = fileformat.getDataset();
	dataset->putAndInsertString(DCM_SOPClassUID,UID_SecondaryCaptureImageStorage);
	dataset->putAndInsertString(DCM_SOPInstanceUID,dcmGenerateUniqueIdentifier(uid,SITE_INSTANCE_UID_ROOT));
	dataset->putAndInsertString(DCM_PatientName,"JOHN");
	OFCondition cond = fileformat.saveFile("testwl.wl",EXS_LittleEndianExplicit);
	if (cond.bad())
	{
		cerr<<"error: can't write dicom file: "<<cond.text()<<endl;
	}
	return 0;
}