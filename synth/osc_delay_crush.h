#ifndef SYNTHTEST_H
#define SYNTHTEST_H
#include "Synth.h"
#include "Modules.h"


class SynthTest : public Synth
{
    public:
    ModuleConstant param[8];

    SynthTest()
    {

        //Define Node Objects
    ModuleDelay *moduleDelay_1 = new ModuleDelay();
    ModuleBitReducer *moduleBitReducer_1 = new ModuleBitReducer();
    ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
    ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
    ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();

    moduleDelay_1->mix_input = new ModuleConstant(800);
    moduleDelay_1->feedback_input = new ModuleConstant(900);
    moduleDelay_1->length_input = new ModuleConstant(1023);
    moduleBitReducer_1->bit_input= &param[1];
    moduleDelay_1->audio_input=moduleBitReducer_1;
    moduleMixer2_1->ch1=moduleWavetableOsc_1;
    moduleMixer2_1->ch2=moduleWavetableOsc_2;
    moduleBitReducer_1->audio_input=moduleMixer2_1;
    moduleWavetableOsc_1->frequency_input= &param[0];
    moduleWavetableOsc_2->frequency_input= &param[2];


    this->last_module = moduleDelay_1;

    }
};
#endif // SYNTHTEST_H


/*

This is espnode86 stuff do not edit

--BEGINESPNODEPATCH--
djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA0dXFhIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIDR1cWEKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2cnpr
IGVzcG5vZGUvZGVsYXkgQXVkaW8lMjBEZWxheQpub2RlL3R1cm4tb24gdnJ6awpub2RlL2FkZC1pbmxldCB2cnprIHRpM28gZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgdnJ6ayBveHdyIGVzcG5vZGUvc3RyaW5n
IG1peF9pbnB1dCBtaXhfaW5wdXQKbm9kZS9hZGQtaW5sZXQgdnJ6ayB4Y2h3IGVzcG5vZGUvc3RyaW5nIGZlZWRiYWNrX2lucHV0IGZlZWRiYWNrX2lucHV0Cm5vZGUvYWRkLWlubGV0IHZyemsgOHpzeSBlc3Bub2RlL3N0cmluZyBsZW5ndGhfaW5wdXQgbGVuZ3Ro
X2lucHV0Cm5vZGUvYWRkLW91dGxldCB2cnprIDRhbDIgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDQzZHAgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIDQzZHAKbm9kZS9hZGQtaW5sZXQgNDNkcCA0OW5mIGVz
cG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgMXpvcyBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiAxem9zCm5vZGUvYWRkLW91dGxldCAxem9zIHpjaWwgZXNwbm9kZS9zdHJp
bmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCAxem9zIGcwbTkgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCAxem9zIHRieHUgZXNwbm9kZS9zdHJpbmcgUG90MyBQb3QzCm5vZGUvYWRkLW91dGxldCAxem9zIDU4amEgZXNwbm9kZS9z
dHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCAxem9zIGZudzAgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCAxem9zIDhjbTYgZXNwbm9kZS9zdHJpbmcgUG90NiBQb3Q2Cm5vZGUvYWRkLW91dGxldCAxem9zIGU0NW4gZXNwbm9k
ZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCAxem9zIG45bWIgZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgY2Q1ZiBlc3Bub2RlL2NvbnN0YW50IENvbnN0YW50JTdDMC0xMDIzCm5vZGUvdHVybi1vbiBjZDVmCm5v
ZGUvYWRkLWlubGV0IGNkNWYgYWRjZyBlc3Bub2RlL3N0cmluZyB1c2VyLXZhbHVlIHVzZXItdmFsdWUKbm9kZS9hZGQtb3V0bGV0IGNkNWYgd2szZiBlc3Bub2RlL3N0cmluZyBudW1iZXIgbnVtYmVyCnBhdGNoL2FkZC1ub2RlIHNhZDQgdnh1cyBlc3Bub2RlL2Nv
bnN0YW50IENvbnN0YW50JTdDMC0xMDIzCm5vZGUvdHVybi1vbiB2eHVzCm5vZGUvYWRkLWlubGV0IHZ4dXMgczQ4byBlc3Bub2RlL3N0cmluZyB1c2VyLXZhbHVlIHVzZXItdmFsdWUKbm9kZS9hZGQtb3V0bGV0IHZ4dXMgdXV2cCBlc3Bub2RlL3N0cmluZyBudW1i
ZXIgbnVtYmVyCnBhdGNoL2FkZC1ub2RlIHNhZDQgMXdmMCBlc3Bub2RlL2NvbnN0YW50IENvbnN0YW50JTdDMC0xMDIzCm5vZGUvdHVybi1vbiAxd2YwCm5vZGUvYWRkLWlubGV0IDF3ZjAgcjQxNyBlc3Bub2RlL3N0cmluZyB1c2VyLXZhbHVlIHVzZXItdmFsdWUK
bm9kZS9hZGQtb3V0bGV0IDF3ZjAgaHhmcCBlc3Bub2RlL3N0cmluZyBudW1iZXIgbnVtYmVyCnBhdGNoL2FkZC1ub2RlIHNhZDQgdHJxbSBlc3Bub2RlL2JpdGNydXNoZXIgQml0JTIwQ3J1c2hlcgpub2RlL3R1cm4tb24gdHJxbQpub2RlL2FkZC1pbmxldCB0cnFt
IDNpcjUgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgdHJxbSBtYnFmIGVzcG5vZGUvc3RyaW5nIGJpdF9pbnB1dCBiaXRfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHRycW0gdXMzMiBlc3Bub2RlL3N0cmluZyBPdXQg
T3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgbGp3ZCBlc3Bub2RlL29zY2lsbGF0b3IgT3NjaWxsYXRvcgpub2RlL3R1cm4tb24gbGp3ZApub2RlL2FkZC1pbmxldCBsandkIDNhNG4gZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApu
b2RlL2FkZC1pbmxldCBsandkIGkzbGwgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxlX2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgbGp3ZCBpNTZiIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2YXZwIGVzcG5v
ZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiB2YXZwCm5vZGUvYWRkLWlubGV0IHZhdnAgY3hqMyBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IHZhdnAgMHYzZiBlc3Bub2RlL3N0
cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCB2YXZwIDJpY28gZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHV5bGsgZXNwbm9kZS9taXhlcjIgMiUyMENoJTIwTWl4ZXIKbm9kZS90dXJu
LW9uIHV5bGsKbm9kZS9hZGQtaW5sZXQgdXlsayA2bTA0IGVzcG5vZGUvc3RyaW5nIGNoMSBjaDEKbm9kZS9hZGQtaW5sZXQgdXlsayB2YzNxIGVzcG5vZGUvc3RyaW5nIGNoMiBjaDIKbm9kZS9hZGQtb3V0bGV0IHV5bGsgeW42dSBlc3Bub2RlL3N0cmluZyBPdXQg
T3V0Cm5vZGUvbW92ZSA0dXFhIDMwIDIwCm5vZGUvbW92ZSB2cnprIDEwMzggMjM4Cm5vZGUvbW92ZSA0M2RwIDEyNzEgMjY0Cm5vZGUvbW92ZSAxem9zIDI3MCAxNzcKbm9kZS9tb3ZlIGNkNWYgNzk3IDM2OQpub2RlL21vdmUgdnh1cyA3OTQgNDY5Cm5vZGUvbW92
ZSAxd2YwIDY1NCAzNjgKbm9kZS9tb3ZlIHRycW0gNDYzIDM1Mgpub2RlL21vdmUgbGp3ZCA0ODkgMTAwCm5vZGUvbW92ZSB2YXZwIDQ4MiAxOTYKbm9kZS9tb3ZlIHV5bGsgNzI0IDEzMwpvdXRsZXQvY29ubmVjdCA0YWwyIDQ5bmYgM3hqeQpvdXRsZXQvY29ubmVj
dCB3azNmIDh6c3kgdWZjawpvdXRsZXQvY29ubmVjdCB1dXZwIHhjaHcgdDdvYgpvdXRsZXQvY29ubmVjdCBoeGZwIG94d3IgZ2hsZgpvdXRsZXQvY29ubmVjdCBnMG05IG1icWYgeW1sNApvdXRsZXQvY29ubmVjdCB1czMyIHRpM28gejU2aApvdXRsZXQvY29ubmVj
dCBpNTZiIDZtMDQgdzZrdgpvdXRsZXQvY29ubmVjdCAyaWNvIHZjM3EgbjdmdwpvdXRsZXQvY29ubmVjdCB5bjZ1IDNpcjUgcHV4aQpvdXRsZXQvY29ubmVjdCB6Y2lsIDNhNG4gMzdqNQpvdXRsZXQvY29ubmVjdCB0Ynh1IGN4ajMgajM3NQpub2RlL3VwZGF0ZS1p
bmxldCB2cnprIG94d3IgbWl4X2lucHV0IDgwMApub2RlL3VwZGF0ZS1pbmxldCB2cnprIHhjaHcgZmVlZGJhY2tfaW5wdXQgOTAwCm5vZGUvdXBkYXRlLWlubGV0IHZyemsgOHpzeSBsZW5ndGhfaW5wdXQgMTAyMwpub2RlL3VwZGF0ZS1pbmxldCA0M2RwIDQ5bmYg
YXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1vdXRsZXQgY2Q1ZiB3azNmIG51bWJlciAxMDIzCm5vZGUvdXBkYXRlLWlubGV0IGNkNWYgYWRjZyB1c2VyLXZhbHVlIDEwMjMKbm9kZS91cGRhdGUtb3V0bGV0IHZ4dXMgdXV2cCBudW1iZXIgOTAwCm5vZGUvdXBkYXRl
LWlubGV0IHZ4dXMgczQ4byB1c2VyLXZhbHVlIDkwMApub2RlL3VwZGF0ZS1vdXRsZXQgMXdmMCBoeGZwIG51bWJlciA4MDAKbm9kZS91cGRhdGUtaW5sZXQgMXdmMCByNDE3IHVzZXItdmFsdWUgODAwCm5vZGUvdXBkYXRlLWlubGV0IHRycW0gbWJxZiBiaXRfaW5w
dXQgMApub2RlL3VwZGF0ZS1pbmxldCBsandkIDNhNG4gZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgbGp3ZCBpM2xsIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHZhdnAgY3hqMyBmcmVxdWVuY3lfaW5wdXQgMApub2RlL3Vw
ZGF0ZS1pbmxldCB2YXZwIDB2M2Ygd2F2ZXRhYmxlX2lucHV0IDA=
--ENDESPNODEPATCH--

*/
